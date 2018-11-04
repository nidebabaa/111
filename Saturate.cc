//
// Saturate.cc
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#include <string>
#include "flashphoto/filter.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/Saturate.h"
#include "flashphoto/flashphoto_app.h"
#include "flashphoto/image_tools_math.h"

namespace image_tools {
	
Saturate::Saturate(float scale) {
	sat_value_ = scale;
}

Saturate::~Saturate() {}


ColorData Saturate::CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) {
	// initial RGB
	ColorData color = buffer->pixel(x,y); // Get buffer pixel
	
	float red = color.red();
	float green = color.green();
	float blue = color.blue();
	/*convert pixel to grayscale value which is optimized 
	for human vision of the intensity of colors */
	float lum = color.Luminance(); 
	ColorData gray(lum,lum,lum);
	
	ColorData outputcolor = ImageToolsMath::Lerp(gray, color, sat_value_);
	
	return outputcolor;
	
	
}

}  // namespace image_tools 