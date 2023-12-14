/*
@DESIGN
///
//Class to handle object detection for water bottle, mallet and Aruco tags
///
@MODEL
///
//None
///
@ACRONYM
///
//Autonomous Interface for Keypoint Odometry
//愛子: Japanese name meaning "Beloved Child"
///
*/
#include <opencv2/opencv.hpp>
//#include <opencv2/aruco.hpp>
#include <iostream>
#include "./dataTypes/Detection.hh"
#include <vector>
#pragma once
;
namespace Vision{
    class AIKO{
        private:
        cv::dnn::Net model;
        
        std::vector<Detection> detectedObj;
        cv::Mat formatImg(cv::Mat &img);
        
        public:
        AIKO(cv::dnn::Net yolo): model(yolo) {};
        ~AIKO() = default;
        std::vector<Detection> getDetectedObj(){
            return detectedObj;
        }
        std::vector<cv::Mat> readFrame(cv::Mat img); //@TODO change return type to whatever coordinates will be used to locate the pixel 
    };
}