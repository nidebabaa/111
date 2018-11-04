//
// ConvolutionFilter.h 
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#ifndef FLASHPHOTO_CONVOLUTIONFILTER_H_
#define FLASHPHOTO_CONVOLUTIONFILTER_H_

#include <string>
#include "flashphoto/filter.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/mask_factory.h"
#include "flashphoto/float_matrix.h"
#include "flashphoto/image_tools_math.h"

namespace image_tools {

class ConvolutionFilter : public Filter {
	public:
		ConvolutionFilter(FloatMatrix);
		virtual ~ConvolutionFilter();
		
		virtual FloatMatrix* CreateKernel() = 0;
		
		//virtual void SetupFilter();
		virtual ColorData CalculateFilteredPixel(PixelBuffer* buffer, int x, int y) override;
		//virtual void CleanupFilter();
		virtual bool can_calculate_in_place();
		
	protected:
		FloatMatrix* kernel_;
	
};

}  // namespace image_tools

#endif  // FLASHPHOTO_CONVOLUTIONFILTER_H_
