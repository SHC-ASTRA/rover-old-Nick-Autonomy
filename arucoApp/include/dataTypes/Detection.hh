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
namespace Vision{
typedef struct{
    int class_id;
    float confidence;
    cv::Rect box;
}Detection;
}
