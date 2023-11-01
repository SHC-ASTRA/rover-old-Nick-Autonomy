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
#ifndef NAVIGATOR_COMPONENT
#define NAVIGATOR_COMPONENT
#include "dataTypes/GPS.hh"
#include "dataTypes/navStates.hh"
#include "navigators/GlobalNavigator.hh"
#include "navigators/LocalNavigator.hh"
namespace nav{

    class Navigator{
        private:
        GlobalNaviator globalNav;
        LocalNavigator localNav;
        public:
        Navigator();

        ~Navigator() = default;

        void navLoop();

        
        void setCoordinates(GPS newCords);
        
    };
}


#endif