//
// filter.cc 
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#include "flashphoto/filter.h"
#include <string>
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include <iostream>
#include <cmath>

namespace image_tools {
	
Filter::Filter() {}

Filter::~Filter() {}

void Filter::SetupFilter() {}
void Filter::CleanupFilter() {}
bool Filter::can_calculate_in_place() {return true;}

void Filter::ApplyToBuffer(PixelBuffer* buffer){
	if (!can_calulate_in_place()) {
	//PixelBuffer* copybuffer = new PixelBuffer(buffer->width_(), 
											//buffer->height_(), 
											//buffer->background_color_());}
		PixelBuffer copybuffer = *buffer;}
	SetupFilter();
	for (int i = 0; i < buffer.width(); i++) {
		for (int j = 0; j < buffer.height(); j++) {
			//ColorData pixel_data = CalculateFilteredPixel(buffer, i, j);
		buffer->set_pixel(i, j, CalculateFilteredPixel(buffer, i, j));
		}
	}
	CleanupFilter();
	
	// cleanup
}

	
}  // namespace image_tools 
