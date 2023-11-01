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
#ifndef NAV_STATES
#define NAV_STATES
namespace nav{
    enum AutonomousState{
            IDLE =0,
            NAVIGATING,
            SEARCHING,
            CONVERGING,
            GOAL
        };
        
        enum goalType{
            ABORT = 0,
            GNSS,
            POST,
            HAMMER,
            BOTTLE
        };
}
#endif