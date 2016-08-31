#pragma once
#include <opencv\cv.h>
#include <opencv2\highgui\highgui.hpp>
class TrackBarGui
{


public:
	TrackBarGui(void);
	~TrackBarGui(void);
	
	cv::Scalar getUpperLimit();
	cv::Scalar getLowerLimit();

	TrackBarGui( std::string trackBarName );

	void CreateTrackBar();
	void InitializeTrackBarVariables();


private:


	std::string trackBarName;

	int H_MIN;
	int H_MAX; 
	int S_MIN;
	int S_MAX;
	int V_MIN;
	int V_MAX;
};

