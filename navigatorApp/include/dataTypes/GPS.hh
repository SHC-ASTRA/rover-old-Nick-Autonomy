/*
@DESIGN
///
//Typedef of GPS type and localizing it to rover basis
///
@MODEL
///
//https://app.diagrams.net/#G11xkbU996_WanYtTfMBRpjXm4N-WsP5TJ
///
*/
#pragma once
#include <array>
#ifndef GPS_t
#define GPS_t
namespace nav{
    typedef std::array<double,2> GPS;

    GPS vectorize(GPS a, GPS b){
        //@TODO add to model
        GPS result = {a[0]-b[0],a[1]-b[1]};
        return result;
    };
}
#endif