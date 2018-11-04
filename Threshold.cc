//
// Threshold.cc
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#include <string>
#include "flashphoto/filter.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/Threshold.h"
#include "flashphoto/flashphoto_app.h"

namespace image_tools {
	
Threshold::Threshold(float value) {
	value_ = value;
}

Threshold::~Threshold() {}


ColorData Threshold::CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) {
	 // initial RGB
	ColorData color = buffer->pixel(x,y); // Get buffer pixel
	ColorData black = ColorData(0,0,0); // color black
	ColorData white = ColorData(255,255,255); // color white 
	
	float red = color.red();
	float green = color.green();
	float blue = color.blue();
	
	float thresh = (red + green + blue)/3;
	
	if (thresh > value_) {
		color = white;
	}
	else {
		color = black;
	}
	
	return color; 
}
	
} // namespace image_tools 
