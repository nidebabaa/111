//
// Channels.cc
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#include <string>
#include "flashphoto/filter.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/Channels.h"
#include "flashphoto/flashphoto_app.h"

namespace image_tools {
	
Channels::Channels(float red, float green, float blue) {
	red_ = red;
	green_ = green;
	blue_ = blue; 
}

Channels::~Channels() {}


ColorData Channels::CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) {
	float red, green, blue; // initial RGB
	float newred, newgreen, newblue; // initial newRGB
	ColorData color = buffer->pixel(x,y); // Get buffer pixel
	
	red = color.red();
	green = color.green();
	blue = color.blue();
	
	newred = red * red_;
	newgreen = green * green_;
	newblue = blue * blue_;
	
	ColorData outputcolor(newred,newgreen,newblue);
	
	return outputcolor;
	
	
}

}  // namespace image_tools 
