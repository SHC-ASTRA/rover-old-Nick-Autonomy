
#pragma once 
#include "rclcpp/rclcpp.hpp"

class AutonomyNode: public rclcpp::Node{
    

    public:
    AutonomyNode(): rclcpp::Node("Autonomy") {};
};