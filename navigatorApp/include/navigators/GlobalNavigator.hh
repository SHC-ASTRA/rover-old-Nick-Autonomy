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
#include "Daedalus.hh"
#ifndef GLOABAL_NAV
#define GLOBAL_NAV
namespace nav{
    class GlobalNaviator : Daedalus{
        public:
        bool executeNav() override;
    };
}
#endif
