#include "TrackBarGui.h"
#include "FileCapture.h"
#include "CameraCapture.h"

#include "GreenScreen.h"

int main( int argc, char** argv ){
	
	
	
	FileCapture fileCaptureObjectTo;
	FileCapture	fileCaptureObjectFrom;
	GreenScreen greenScreenObject;
	TrackBarGui BarGui( "HSV Bar" ) ; 
	
	BarGui.CreateTrackBar();
	
	
	
	cv::Mat green_image;
	cv::Mat sample_image;
	
	std::string fileUriGreen= "C:/greenscreentest/05.mp4";
	std::string fileUriSample = "C:/greenscreentest/02.jpg";


	int feed = 1;
	
	while( feed ==  1 ){

		if( !fileCaptureObjectTo.OpenFile( fileUriGreen ) || !fileCaptureObjectFrom.OpenFile( fileUriSample ) ){
			break;
		}
		if(!fileCaptureObjectFrom.Capture( sample_image )) break;
		
		while( feed == 1 ){
			if(!fileCaptureObjectTo.Capture( green_image ) ) {
				break;
			}
			cv::Mat masked_image;
			cv::Mat bin_image;
			cv::Mat hsv_greenImage;

			cv::cvtColor(green_image, hsv_greenImage, CV_RGB2YCrCb);
			imshow("image hsv", hsv_greenImage);
			cv::inRange( hsv_greenImage, BarGui.getLowerLimit(), BarGui.getUpperLimit(), bin_image );
			
			cv::imshow( "foo", bin_image );

			cv::Mat copy_green_image( green_image );
			masked_image = greenScreenObject.Mask( copy_green_image, sample_image, bin_image  ); 


			cv::imshow( "video1", green_image );
			cv::imshow( "masked", masked_image );
			if( cv::waitKey(10) == 27){
				std::cout << "Escape key hit" << std::endl;
				break;
			}
		}
		
	}

}