#include "GreenScreen.h"
#include <opencv\highgui.h>

GreenScreen::GreenScreen(void)
{
	
}


GreenScreen::~GreenScreen(void)
{
}

cv::Mat GreenScreen::Mask( cv::Mat green_image, cv::Mat sample_image, cv::Mat  bin_image )
{

	
	cv::Mat hsv_greenImage;
	//Threshold
	//cv::cvtColor(green_image, green_image, CV_RGB2HSV);
	

	cv::Mat copy_green_image( green_image );
	for( int i=0; i<green_image.rows; i++){
	
		for( int j=0; j<green_image.cols; j++ ){
			
			if(bin_image.at<uchar>(i, j)==255){
				green_image.at<cv::Vec3b>(i, j)= sample_image.at<cv::Vec3b>(i, j); 

			}
		}
	}
	return green_image;
}

