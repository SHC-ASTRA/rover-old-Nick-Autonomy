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
#include <unordered_map>
#pragma once
;
namespace Vision{
    class AIKO{
        private:
        cv::dnn::Net model;
        
        std::vector<Detection> detectedObj;
        cv::Mat formatImg(cv::Mat &img);
        int state;
        int goal;
        std::unordered_map<int, bool> visitedTags = {{0,false},{1,false}, {2,false},{3,false}};
        public:
        AIKO(cv::dnn::Net yolo): model(yolo) {};
        ~AIKO() = default;
        std::vector<Detection> getDetectedObj(){
            return detectedObj;
        }
        void setVisitedTag(int id){
            visitedTags.insert({id,true});
        }
        void setState(int newState) {state = newState;};
        void setGoal(int newGoal) {goal= newGoal;};
        std::vector<cv::Mat> readFrame(cv::Mat img); //@TODO change return type to whatever coordinates will be used to locate the pixel 
    };
}