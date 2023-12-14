/*
@DESIGN
///
//Realizes Ros interface for all autonomous needs 
///
@MODEL
///
//None
///
*/
#pragma once 
#include "rclcpp/rclcpp.hpp"

class AutonomyNode: public rclcpp::Node{
    private: 
    void GPS_UPDATE_CALLBACK();
    void IMU_UPDATE_CALLBACK();
    void RECEIVED_STATE_CALLBACK();
    void TARGET_RECEIVED_CALLBACK();

    public:
    AutonomyNode(): rclcpp::Node("Autonomy") {};

};