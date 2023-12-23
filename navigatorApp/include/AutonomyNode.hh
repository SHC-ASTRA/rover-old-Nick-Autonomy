#pragma once 
#include <memory>
#include <chrono>
#include <iostream>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/int8.hpp"
#include "nav.hh"

using std::placeholders::_1;
using namespace std::chrono_literals;
class AutonomyNode: public rclcpp::Node{
    private:
    std::shared_ptr<nav::Navigator> navigator_;
    rclcpp::Subscription<std_msgs::msg::Int8>::SharedPtr targetSubscription_;
    rclcpp::Subscription<std_msgs::msg::Int8>::SharedPtr stateSubscription_;
    rclcpp::Publisher<std_msgs::msg::Int8>::SharedPtr statePublisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    void target_sub_callback(const std_msgs::msg::Int8 target){
        navigator_->setTarget(target.data);
    };
    void state_sub_callback(const std_msgs::msg::Int8 state){
        navigator_->setState(state.data);
    };
    void timedPublishCallback(){
        //std_msgs::msg::Int8 message;
        //message.data = navigator_->getState();
        //statePublisher_->publish(message);
    };
    public:
    AutonomyNode(): rclcpp::Node("astra_autonomy"){};
    AutonomyNode(std::shared_ptr<nav::Navigator> nav_): rclcpp::Node("astra_autonomy"){
        navigator_ = nav_;
        navigator_->setState(nav::GOAL);
        std::cout <<navigator_->getState() << "here" <<std::endl;
        targetSubscription_ = this->create_subscription<std_msgs::msg::Int8>("astra/auto/setTarget",8,std::bind(&AutonomyNode::target_sub_callback,this,_1));
        stateSubscription_ = this->create_subscription<std_msgs::msg::Int8>("astra/auto/setState",8,std::bind(&AutonomyNode::state_sub_callback,this,_1));
        statePublisher_ = this->create_publisher<std_msgs::msg::Int8>("astra/auto/setState",8);
        timer_ = this->create_wall_timer(500ms,std::bind(&AutonomyNode::timedPublishCallback,this)); //Reporting at 2 hz
    };
};