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
        GlobalNavigator globalNav;
        LocalNavigator localNav;
        int8_t state = IDLE;
        int8_t target = ABORT;
        public:
        Navigator(){
            
        };

        ~Navigator() = default;

        void navLoop();

        void setState(int8_t newState){
            if(newState > GOAL || newState < IDLE){
                std::cout << "Failed to update state";
                return;
            }
            state = newState;
        };
        int8_t getState(){
            return state;
        }
        void setTarget(int8_t newTarget){
            if(newTarget > BOTTLE || newTarget < ABORT){
                std::cout << "Failed to update target";
                return;
            }
            target = newTarget;
        };
        void setCoordinates(GPS newCords);
        
    };
}


#endif