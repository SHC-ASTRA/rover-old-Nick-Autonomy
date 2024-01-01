#include "../include/AIKO.hh"
#include "../include/dataTypes/VisionConstants.hh"
#include <opencv2/opencv.hpp>
#include <opencv2/aruco.hpp>
#include <vector>
#include "../include/dataTypes/Detection.hh"
#include "../../navigatorApp/include/dataTypes/navStates.hh"
#include <algorithm>
cv::Mat Vision::AIKO::formatImg(cv::Mat &img){
    std::cout <<"Beginning image reformatting" << std::endl;
    int col = img.cols;
    int row = img.rows;
    cv::Mat formattedImg = cv::Mat::zeros(640,640,CV_8UC3);
    img.copyTo(formattedImg(cv::Rect(0,0,col,row)));
    return(formattedImg);
}


std::vector<Vision::Detection> Vision::AIKO::readFrame(cv::Mat &input_img){
    std::vector<Vision::Detection> outputOverlays;
    cv::Mat img = input_img;
    if((state ==nav::SEARCHING || state == nav::CONVERGING) && goal == nav::POST){
        cv::Mat newImg;
        img.copyTo(newImg);
        std::vector<int> markerIds;
        std::vector<std::vector<cv::Point2f>> corners, rejected;
        Vision::detector.detectMarkers(img,corners,markerIds,rejected);
        if(markerIds.size() > 0){
            for(int i =0;i<markerIds.size();i++){
                std::cout << markerIds[i] << std::endl;
                if(!visitedTags[markerIds[i]]){//TODO adjust frame count before switching states
                    //cv::aruco::drawDetectedMarkers(newImg,corners,markerIds);
                    Vision::Detection output;
                    output.class_id = "Post" + std::to_string(markerIds[i]);
                    int maxX = 0;
                    int maxY = 0;
                    int minX = 640;
                    int minY = 640;
                    for(int j =0;j<corners.size();j++){
                        for(int k=0;k<corners[j].size();k++){
                            if(corners[j][k].x > maxX){
                                maxX = corners[j][k].x;
                            }
                            else if(corners[j][k].x < minX){
                                minX = corners[j][k].x;
                            }
                            if(corners[j][k].y > maxY){
                                maxY = corners[j][k].y;
                            }
                            else if(corners[j][k].y < minY){
                                minY = corners[j][k].y;
                            }
                        }
                    }
                    cv::Point tr(maxX,maxY);
                    cv::Point bl(minX,minY);
                    std::cout << tr.x <<", " << tr.y<< std::endl;
                    std::cout << bl.x <<", " <<bl.y <<std::endl;
                    output.box = cv::Rect(tr,bl);
                    outputOverlays.push_back(output);
                }
            }
        }
        else{
            std::cout <<"No tag found" <<std::endl; //debug print
        }
    }
    else{
        std::cout <<"AI processing time" << std::endl;
        //cv::Size modelShape(input_img.rows,input_img.cols);
        cv::Size inShape(img.rows,img.cols);
        cv::Size modelShape(640,640);
        img = formatImg(input_img);
        std::cout <<"Image successfully resized" << std::endl;
        std::cout <<"Creating blob" << std::endl;
        cv::Mat blob;
        cv::dnn::blobFromImage(img,blob,1.0/255.0,modelShape,cv::Scalar(),true,false);
        model.setInput(blob);

        std::cout <<"Blob created\nGetting model outputs" << std::endl;
        std::vector<cv::Mat> outputs;
        model.forward(outputs,model.getUnconnectedOutLayersNames());
        std::cout <<"Model outputs computed\nUnpacking output Layers" << std::endl;
        //yolov8 specific
        int rows = outputs[0].size[2];
        int dims = outputs[0].size[1];

        outputs[0] = outputs[0].reshape(1,dims);
        cv::transpose(outputs[0],outputs[0]);

        //Non specific
        float *data = (float *)outputs[0].data;
        
        float xResizeFactor = img.cols/inShape.width;
        float yResizeFactor = img.rows/inShape.height;

        std::vector<int> class_ids;
        std::vector<float> confidences;
        std::vector<cv::Rect> boxes;

        for(int i =0;i<rows;++i){
            //yolov8 specific
            float *classes_scores = data+4;

            cv::Mat scores(1,Vision::classes.size(),CV_32FC1,classes_scores);
            cv::Point class_id;
            double maxClassScore;

            cv::minMaxLoc(scores,0,&maxClassScore,0,&class_id);
            
            if(maxClassScore > Vision::SCORE_THRESHOLD){
                confidences.push_back(maxClassScore);
                class_ids.push_back(class_id.x);

                float x = data[0];
                float y = data[1];
                float w = data[2];
                float h = data[3];
                
                int left = int((x-0.5*w)*xResizeFactor);
                int top = int((y-0.5*h)*yResizeFactor);

                int width = int(w*xResizeFactor);
                int height = int(h*yResizeFactor);

                boxes.push_back(cv::Rect(left,top,width,height));
            }
            data+=dims;
    }
    std::vector<int> nmsResult;
    cv::dnn::NMSBoxes(boxes,confidences,Vision::SCORE_THRESHOLD,Vision::NMS_THRESHOLD,nmsResult);
    for(unsigned long i=0;i<nmsResult.size();++i){
        int idx = nmsResult[i];
        Vision::Detection objectFound;
        objectFound.class_id = class_ids[idx];
        objectFound.confidence = confidences[idx];
        objectFound.box = boxes[idx];
        outputOverlays.push_back(objectFound);
    }
    std::cout << "Image processing Complete" << std::endl;
    }
    
    //TODO: TEST DETECTION FOR WATER BOTTLE AND HAMMER
    return(outputOverlays);
    
}