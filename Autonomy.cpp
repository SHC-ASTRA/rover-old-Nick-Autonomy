#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>
#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include <AutonomyNode.hh>
#include <opencv2/aruco.hpp>
#include <librealsense2/rs.hpp>
#include <AIKO.hh>
#include "navigatorApp/include/dataTypes/navStates.hh"
#include <thread>
#include <memory>

auto navigationHandler = std::make_shared<nav::Navigator>();
void setupRos(int argc, char * argv[],std::shared_ptr<AutonomyNode> nodeHandler){
    rclcpp::spin(nodeHandler);
    rclcpp::shutdown();
}

void testImgRead(){
    std::vector<Vision::Detection> identifiedObjs;
    cv::dnn::Net net = cv::dnn::readNetFromONNX("/home/octoprint/ros2_ws/src/rover-Autonomy/arucoApp/src/best.onnx");//TODO find the file locally (it stopped doing that for some reason)
    cv::String filepath = "/home/octoprint/ros2_ws/src/rover-Autonomy/testImgs/*.png";//See above comment
    Vision::AIKO seeker(net);
    int detectNum = 0;
    seeker.setState(nav::SEARCHING);
    seeker.setGoal(nav::POST);
    std::vector<cv::String> fileNames;
    std::vector<cv::Mat> processedImgs;
    cv::glob(filepath,fileNames);
    for(size_t file = 0; file<fileNames.size();file++){
        cv::Mat img = cv::imread(fileNames[file]); 
        std::cout << fileNames[file] << std::endl;
        identifiedObjs = seeker.readFrame(img);
        for(int i=0;i<identifiedObjs.size();i++){
            cv::rectangle(img,identifiedObjs[i].box,1,8,0);
            cv::imshow("Display",img);
            int k = cv::waitKey(0);
        }
    }
}

void autonomousControl(std::shared_ptr<AutonomyNode> nodeHandler){
    testImgRead(); 
    while(true){
     switch(navigationHandler->getState()){
        case nav::IDLE:
        break;
        case nav::NAVIGATING:
        if(navigationHandler->globalNav.getTargetDistance() <=3){
            if(navigationHandler->getTarget() == nav::GNSS){
                navigationHandler->setState(nav::GOAL);
            }
            else{
                navigationHandler->setState(nav::SEARCHING);
            }
        }
        else{
            //NAVIGATE HERE
        }
        break;
        case nav::SEARCHING:
        break;
        case nav::CONVERGING:
        break;
        case nav::GOAL:
        break;
        default:
        navigationHandler->setState(nav::IDLE);
        break;
     }
    }
}

int main(int argc,char * argv[]){
    rclcpp::init(argc,argv);
    auto nodeHandler = std::make_shared<AutonomyNode>(navigationHandler);
    std::thread rosHandler(setupRos,argc,argv,nodeHandler);
    std::thread navHandler(autonomousControl,nodeHandler);
    rosHandler.join();
    navHandler.join();
    return 0;
}
