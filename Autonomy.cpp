#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>
#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include <AutonomyNode.hh>
#include <opencv2/aruco.hpp>
#include <librealsense2/rs.hpp>
void setupRos(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<AutonomyNode>());
    rclcpp::shutdown();//Dev function call 
}



int main(int argc,char * argv[]){
    //nav::Navigator navi;
    std::cout << "Here" << std::endl;
    //setupRos(argc,argv);
    std::cout <<"here" <<std::endl;
    return 0;
}
