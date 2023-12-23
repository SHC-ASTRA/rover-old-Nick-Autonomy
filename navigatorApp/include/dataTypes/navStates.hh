/*
@DESIGN
///
//Declares target state type
//Declares navigation state type
///
@MODEL
///
//https://app.diagrams.net/#G11xkbU996_WanYtTfMBRpjXm4N-WsP5TJ
///
*/
#pragma once
#ifndef NAV_STATES
#define NAV_STATES
#include <stdint.h>
namespace nav{
    enum AutonomousState: int8_t{
            IDLE =0,//Waiting
            NAVIGATING,//going to GNSS location
            SEARCHING,//Looking for object of interest
            CONVERGING,//Approaching found object of interest
            GOAL//:D
        };
        
        enum goalType: int8_t{
            ABORT = 0,
            GNSS,
            POST,
            HAMMER,
            BOTTLE
        };
}
#endif