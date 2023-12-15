#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>
#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include <AutonomyNode.hh>
#include <opencv2/aruco.hpp>
#include <librealsense2/rs.hpp>
#include <AIKO.hh>
#include "navigatorApp/include/dataTypes/navStates.hh"
void setupRos(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<AutonomyNode>());
    rclcpp::shutdown();//Dev function call 
}



int main(int argc,char * argv[]){
    cv::dnn::Net net = cv::dnn::readNetFromONNX("/home/octoprint/ros2_ws/src/rover-Autonomy/arucoApp/src/yolov5s.onnx");
    cv::String filepath = "/home/octoprint/ros2_ws/src/rover-Autonomy/testImgs/*.png";
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
    return 0;
}
