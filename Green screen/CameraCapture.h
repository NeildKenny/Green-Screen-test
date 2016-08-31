#pragma once

#include <opencv\cv.h>
#include <opencv\highgui.h>
class CameraCapture
{
private: 
	cv::VideoCapture captureObject;
	cv::Mat camImage;
public:
	CameraCapture(void);
	~CameraCapture(void);
	cv::Mat Capture(void);
};

