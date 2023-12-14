#include <opencv2/opencv.hpp>
#include <fstream>
#include <iostream>
#include "../include/AIKO.hh"
#include "../include/dataTypes/Detection.hh"
#include <vector>

/*
Steps to make onnx:
Clone yolov5 repo
install torch torchvision torchaudio
install onnx
install ultralytics
export.py --weights yolov5s --include onnx --simplify
check with
detect.py --weights yolov5s --dnn --source 0

*/
/*
This implementation will be made for the debug environment and will later be upgraded to interface with the depth camera
*/
int main(){

}