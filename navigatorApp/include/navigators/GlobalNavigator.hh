/*
@DESIGN
///
//Handler for global navigator, vote is based on GPS feedback
///
@MODEL
///
//https://app.diagrams.net/#G1QeXQ8Aib6fpu_j5EKg3SoASwzOsPEGVd
///
*/
#pragma once
#include "Daedalus.hh"
#ifndef GLOBAL_NAV
#define GLOBAL_NAV
namespace nav{
    
    class GlobalNavigator: Daedalus{
        public:
        bool executeNav();
    };
}
#endif
