//
// filter.h 
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#ifndef FLASHPHOTO_FILTER_H_
#define FLASHPHOTO_FILTER_H_

#include <string>
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include <iostream>

namespace image_tools {

class Filter {
	public:
		Filter();
		virtual ~Filter();
		
		void ApplyToBuffer(PixelBuffer* buffer);
		
		virtual void SetupFilter();
		virtual void CleanupFilter();
		virtual ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y)=0;
		
		virtual bool can_calculate_in_place(); 
};

}  // namespace image_tools

#endif  // FLASHPHOTO_FILTER_H_
