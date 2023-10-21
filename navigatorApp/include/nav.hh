#ifndef NAVIGATOR_COMPONENT
#define NAVIGATOR_COMPONENT
#include <array>

namespace nav{
    typedef std::array<double,2> GPS;
    
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

    class Navigator{
        private:
        
        GPS target;
        
        GPS current;
        GPS previous;
        //Make an IMU generic for heading

        bool AllowNav = false;
        
        int targetState = IDLE;

        int goalState = ABORT;
        public:
        Navigator();

        ~Navigator() = default;

        bool executeGlobalNav();
        
        bool executeLocalNav();

        void navLoop();

        void setTarget(GPS newTarget){
            target = newTarget;
        }

        int getTarget_State(){
            return targetState;
        }
        void setGoal(int newGoal){
            goalState= newGoal;
        }
        void setCoordinates(GPS newCords);
        GPS vectorize(GPS a, GPS b);

        void DummyGetCords();//TODO remove this when we get the Actual IF
    };
}


#endif