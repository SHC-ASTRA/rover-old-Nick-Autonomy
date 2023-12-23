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
void setupRos(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<AutonomyNode>(navigationHandler));
    rclcpp::shutdown();//Dev function call 
}

void testImgRead(){
    cv::dnn::Net net = cv::dnn::readNetFromONNX("/home/octoprint/ros2_ws/src/rover-Autonomy/arucoApp/src/yolov5s.onnx");//TODO find the file locally (it stopped doing that for some reason)
    cv::String filepath = "/home/octoprint/ros2_ws/src/rover-Autonomy/testImgs/*.png";//See above comment
    Vision::AIKO seeker(net);
    seeker.setState(nav::SEARCHING);
    seeker.setGoal(nav::POST);
    std::vector<cv::String> fileNames;
    std::vector<cv::Mat> processedImgs;
    cv::glob(filepath,fileNames);
    for(size_t file = 0; file<fileNames.size();file++){
        cv::Mat img = cv::imread(fileNames[file]);
        std::cout << fileNames[file] << std::endl;
        seeker.readFrame(img);
    }
}

void autonomousControl(){
    while(true){
     switch(navigationHandler->getState()){
        case nav::IDLE:
        break;
        case nav::NAVIGATING:
        break;
        case nav::SEARCHING:
        break;
        case nav::CONVERGING:
        break;
        case nav::GOAL:
        break;
        case default:
        navigationHandler->setState(nav::IDLE);
        break;
     }
    }
}

int main(int argc,char * argv[]){
    std::thread rosHandler(setupRos,argc,argv);
    std::thread navHandler(autonomousControl);
    rosHandler.join();
    navHandler.join();
    return 0;
}
