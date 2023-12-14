/*
@DESIGN
///
//Declares states and modes for AIKO
///
@MODEL
///
//None
///
*/

#pragma once
#include <stdint.h>
#include <vector>
#include <string>
#include <opencv2/aruco.hpp>
namespace Vision{
    
    const char* COCO_NAME = "bottle";//@TODO include hammer
    
    const float WIDTH = 640.0;
    const float HEIGHT =640.0;
    const float SCORE_THRESHOLD = 0.5;
    const float NMS_THRESHOLD = 0.45f;
    const float CONFIDENCE_THRESHOLD = 0.45f;

    cv::aruco::DetectorParameters detectorParams = cv::aruco::DetectorParameters();
    cv::aruco::Dictionary dictionary = cv::aruco::getPredefinedDictionary(cv::aruco::DICT_4X4_50 );
    cv::aruco::ArucoDetector detector(dictionary,detectorParams);
    // Text parameters.
    const float FONT_SCALE = 0.7f;
    const int FONT_FACE = cv::FONT_HERSHEY_SIMPLEX;
    const int THICKNESS = 1;

    std::vector<std::string> className;//@TODO make this the water bottle 

    cv::Scalar BLACK = cv::Scalar(0,0,0);
    cv::Scalar BLUE = cv::Scalar(255, 178, 50);
    cv::Scalar YELLOW = cv::Scalar(0, 255, 255);
    cv::Scalar RED = cv::Scalar(0,0,255);
    enum AIKO_STATES{
        ARUCO,
        BOTTLE,
        HAMMER
    };
}