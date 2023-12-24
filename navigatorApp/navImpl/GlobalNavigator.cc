#include "../include/navigators/GlobalNavigator.hh"
#include "../include/dataTypes/GPS.hh"
#include <math.h>
#include "../include/dataTypes/navConstants.h"
#define PI 3.14159265358979323846

bool nav::GlobalNavigator::executeNav(){
    //First check for new GPS data, if none request new packet (needs to be handled by the teensy IF (will be attribute to navigator component))
    //On callback return true then the next step can run, this is the real brains of global nav
    nav::GPS heading = nav::vectorize(current,previous);
    nav::GPS targetFromRover = nav::vectorize(target,current);
    long double dot = heading[0]*targetFromRover[0]+heading[1]*targetFromRover[1];
    long double cross = heading[0]*targetFromRover[1]-heading[1]*targetFromRover[0];
    long double errorAngle = atan2(cross,dot)*180/PI;
    return true;
}

double nav::GlobalNavigator::getTargetDistance(){
    //Uses haversine formula to calculate distance in meters
    double phi1 = current[0]*PI/180;
    double phi2 = target[0]*PI/180;
    double deltaPhi = (target[0]-current[0])*PI/180;
    double deltaLambda = (target[1]-current[1])*PI/180;
    double a = sin(deltaPhi/2)*sin(deltaPhi/2)+cos(phi1)*cos(phi2)*sin(deltaLambda/2)*sin(deltaLambda/2);
    double c = 2*atan2(sqrt(a),sqrt(1-a));
    double dist = EARTH_RADIUS*c;
    return dist;
}