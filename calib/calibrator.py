import cv2
import numpy as np
import os.path

#Note: Switch the prints to be roslogs
class calibrator:
    def __init__(self,calibPath="calibration_pictures",type="stereo"):
        print("Begin Calibration Cycle")
        self.BoardSize = (1,1) #Size of the chessboard that will be calibrated against
        self.Points3D = []
        self.leftPoints = []
        self.rightPoints = []
        self.type = "type"
        if not self.is_calibrated():
            self.calibrate()


    def is_calibrated(self):
        print("Checking Cached Calibration Status")
        if os.path.isfile("calibName.txt"):#Switch this to search for the specific calibration images for the camera
            print("Camera Calibrated")
            return True
        else:
            print("Cameras not Calibrated")
            return False

    def calibrate(self):
        print("Calibrating Camera...")

    