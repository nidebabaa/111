//
// Quantize.h 
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#ifndef FLASHPHOTO_TOOL_QUANTIZE_H_
#define FLASHPHOTO_TOOL_QUANTIZE_H_

#include <string>
#include "flashphoto/filter.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/flashphoto_app.h"

namespace image_tools {

class Quantize : public Filter {
	public:
		Quantize(int);
		virtual ~Quantize();
		virtual ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;
	private:
		int bins_;
	
};

}  // namespace image_tools

#endif  // FLASHPHOTO_QUANTIZE_H_
