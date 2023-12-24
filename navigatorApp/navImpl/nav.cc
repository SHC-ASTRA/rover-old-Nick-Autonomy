#include "../include/nav.hh"
#include <math.h>
#include <stdint.h>

void nav::Navigator::setState(int8_t newState){
    if(newState > GOAL || newState < IDLE){
        std::cout << "Failed to update state";
        return;
    }
    state = newState;
};

void nav::Navigator::setTarget(int8_t newTarget){
    if(newTarget > BOTTLE || newTarget < ABORT){
        std::cout << "Failed to update target";
        return;
    }
    target = newTarget;
};

void nav::Navigator::setCoordinates(GPS newCords){
    if(!current[0]){
        current = newCords;
        prev = newCords;
    }
    else{
        prev = current;
        current = newCords;
    }
}