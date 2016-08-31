#include "TrackBarGui.h"


TrackBarGui::TrackBarGui( std::string _trackBarName )
{
	trackBarName = _trackBarName; 

}

void TrackBarGui::InitializeTrackBarVariables(){
	H_MIN = 0;
	H_MAX = 256;
	S_MIN = 0;
	S_MAX = 256;
	V_MIN = 0;
	V_MAX = 256;

}
void TrackBarGui::CreateTrackBar(){

	InitializeTrackBarVariables();
	
	cv::namedWindow(trackBarName, 0);

	cv::createTrackbar( "Hue min", trackBarName, &H_MIN, H_MAX );
	cv::createTrackbar( "Hue max", trackBarName, &H_MAX, H_MAX );
	cv::createTrackbar( "Sat min", trackBarName, &S_MIN, S_MAX );
	cv::createTrackbar( "Sat max", trackBarName, &S_MAX, S_MAX );
	cv::createTrackbar( "Val min", trackBarName, &V_MIN, V_MAX );
	cv::createTrackbar( "Val max", trackBarName, &V_MAX, V_MAX );
	
}

cv::Scalar TrackBarGui::getLowerLimit()
{
	return cv::Scalar( H_MIN, S_MIN, V_MIN );

}

cv::Scalar TrackBarGui::getUpperLimit()
{
	return cv::Scalar( H_MAX, S_MAX, V_MAX );

}

TrackBarGui::TrackBarGui(void)
{
}

TrackBarGui::~TrackBarGui(void)
{
}
