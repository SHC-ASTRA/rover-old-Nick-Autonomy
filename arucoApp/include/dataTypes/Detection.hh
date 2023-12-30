/*
@DESIGN
///
//Structure to hold object detection data
///
@MODEL
///
//None
///
*/
#pragma once 
#include <opencv2/opencv.hpp>
#include <string>
namespace Vision{
typedef struct{
    std::string class_id;
    float confidence;
    cv::Rect box;
}Detection;
}
