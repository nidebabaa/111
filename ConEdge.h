//
// ConEdge.h
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#ifndef FLASHPHOTO_CONEDGE_H_
#define FLASHPHOTO_CONEDGE_H_

#include <string>
#include "flashphoto/filter.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/ConvolutionFilter.h"
#include "flashphoto/mask_factory.h"
#include "flashphoto/float_matrix.h"

namespace image_tools {

class ConEdge : public ConvolutionFilter {
	public:
		ConEdge();
		virtual ~ConEdge();
		FloatMatrix* CreateKernel();
	
};

}  // namespace image_tools

#endif  // FLASHPHOTO_CONEDGE_H_
