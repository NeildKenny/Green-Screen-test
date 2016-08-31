#pragma once

#include <cv.h>
class GreenScreen
{
public:
	GreenScreen(void);
	~GreenScreen(void);

	cv::Mat Mask( cv::Mat green_image, cv::Mat sample_image, cv::Mat bin_image   );
};

