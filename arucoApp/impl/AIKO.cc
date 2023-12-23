#include "../include/AIKO.hh"
#include "../include/dataTypes/VisionConstants.hh"
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <vector>
#include "../include/dataTypes/Detection.hh"
#include "../../navigatorApp/include/dataTypes/navStates.hh"

std::vector<cv::Mat> Vision::AIKO::readFrame(cv::Mat img){
    std::vector<cv::Mat> outputOverlays;
    if(state ==nav::SEARCHING || state == nav::CONVERGING && goal == nav::POST){
        cv::Mat newImg;
        img.copyTo(newImg);
        std::vector<int> markerIds;
        std::vector<std::vector<cv::Point2f>> corners, rejected;
        Vision::detector.detectMarkers(img,corners,markerIds,rejected);
        if(markerIds.size() > 0){
            for(int i =0;i<markerIds.size();i++){
                std::cout << markerIds[i] << std::endl;
                if(!visitedTags[i]){
                    cv::aruco::drawDetectedMarkers(newImg,corners,markerIds);
                    outputOverlays.push_back(newImg);
                }
            }
        }
        else{
            std::cout <<"No tag found" <<std::endl; //debug print
        }
    }
    //TODO: RUN AND UNPACK DETECTION FOR WATER BOTTLE AND HAMMER
    return(outputOverlays);
    
}