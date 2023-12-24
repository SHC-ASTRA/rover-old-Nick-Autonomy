/*
@DESIGN
///
// Declares the nav package and all upper level handlers for navigation
// Acts as highest level component for navigation 
///
@MODEL
///
//https://app.diagrams.net/#G11xkbU996_WanYtTfMBRpjXm4N-WsP5TJ
///
*/
#pragma once
#ifndef NAVIGATOR_COMPONENT
#define NAVIGATOR_COMPONENT
#include "dataTypes/GPS.hh"
#include "dataTypes/navStates.hh"
#include "navigators/GlobalNavigator.hh"
#include "navigators/LocalNavigator.hh"
#include <stdint.h>
#include <iostream>
namespace nav{

    class Navigator{
        private:
        
        int8_t state = IDLE;
        int8_t target = ABORT;
        GPS prev;
        public:
        GlobalNavigator globalNav;
        LocalNavigator localNav;
        GPS current;
        GPS targetLoc;
        Navigator(){
            
        };

        ~Navigator() = default;

        void setState(int8_t newState);
        int8_t getState(){
            return state;
        }

        int8_t getTarget(){
            return target;
        }
        void setTarget(int8_t newTarget);
        void setCoordinates(GPS newCords);
        void setTargetLoc(GPS newTarget){
            targetLoc = newTarget;
        };
        
        
    };
}


#endif