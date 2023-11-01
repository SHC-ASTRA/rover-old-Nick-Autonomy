/*
@DESIGN
///
//Generic type for navigators
///
@MODEL
///
//https://app.diagrams.net/#G1SLY3Kcrk6Ahq0Z1Ak7-C_FUFpgqI9eoJ
///
@ACRONYM
///
//Dynamic Autonomous Exploration and Directional Adaptive Localization for
//Unmanned Systems
///
*/
#pragma once
#include "../dataTypes/GPS.hh"
#include "../dataTypes/navStates.hh"
#ifndef DAEDALUS
#define DAEDALUS
namespace nav{

    class Daedalus{
        protected:
        GPS target;
        GPS current;
        GPS previous;
        bool allowNav = false;
        int targetState = IDLE;
        int goalState = ABORT;
        public:
        Daedalus(){

        };

        ~Daedalus() = default;

        virtual bool executeNav(){
            return false;
        };


    };
}


#endif