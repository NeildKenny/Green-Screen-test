#pragma once


#include <opencv\cv.h>
#include <opencv\highgui.h>
class FileCapture
{

private: 

	cv::VideoCapture captureObject;
public:
	FileCapture(void);
	~FileCapture(void);
	bool Capture(cv::Mat &videoFrame);
	bool OpenFile(std::string filePath);
};

