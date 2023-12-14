#include <opencv2/opencv.hpp>
#include <librealsense2/rs.hpp>
#include "nav.hh"
#include "AutonomyNode.hh"
#include <iostream>
#include "rclcpp/rclcpp.hpp"

void setupRos(int argc, char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<AutonomyNode>());
    rclcpp::shutdown();//Dev function call 
}



int main(int argc,char * argv[]){
    nav::Navigator navi;
    std::cout << "Here" << std::endl;
    setupRos(argc,argv);
    std::cout <<"here" <<std::endl;
    return 0;
}
