/*
@DESIGN
///
//Handler for global navigator, vote is based on IMU and Depth feedback
///
@MODEL
///
//https://app.diagrams.net/#G1WowM8oUnlN4vKx9H3a1Lj0yRx0766ZAL
///
*/
#pragma once
#include "Daedalus.hh"
#ifndef LOCAL_NAV
#define LOCAL_NAV
namespace nav{
    class LocalNavigator: Daedalus{
        public:
        bool executeNav() override{
            return true;
        };
    };
}
#endif