//
// Quantize.cc
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#include <string>
#include "flashphoto/filter.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/Quantize.h"
#include "flashphoto/flashphoto_app.h"

namespace image_tools {
	
Quantize::Quantize(int num) {
	bins_ = num;
}

Quantize::~Quantize() {}


ColorData Quantize::CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) {
	ColorData color = buffer->pixel(x,y); // Get buffer pixel
	
	float red = color.red();
	float green = color.green();
	float blue = color.blue();
	
	int num_steps = bins_ - 1; 
	red = round(red * num_steps)/num_steps;
	green = round(green * num_steps)/num_steps;
	blue = round(blue * num_steps)/num_steps;
	
	ColorData outputcolor(red,green,blue);
	
	return outputcolor;
}

}  // namespace image_tools 


