#include "GlobalNavigator.hh"
#include "../dataTypes/GPS.hh"
#include <math.h>
#define PI 3.14159265358979323846
bool nav::GlobalNaviator::executeNav(){
    //First check for new GPS data, if none request new packet (needs to be handled by the teensy IF (will be attribute to navigator component))
    //On callback return true then the next step can run, this is the real brains of global nav
    GPS heading = vectorize(current,previous);
    GPS targetFromRover = vectorize(target,current);
    long double dot = heading[0]*targetFromRover[0]+heading[1]*targetFromRover[1];
    long double cross = heading[0]*targetFromRover[1]-heading[1]*targetFromRover[0];
    long double errorAngle = atan2(cross,dot)*180/PI;
    //Use teensy IF to turn rover and await turn complete to continue
}