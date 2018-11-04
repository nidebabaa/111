//
// ConBlur.cc
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#include <string>
#include "flashphoto/filter.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/ConvolutionFilter.h"
#include "flashphoto/mask_factory.h"
#include "flashphoto/float_matrix.h"
#include "flashphoto/ConBlur.h"

namespace image_tools {
	
ConBlur::ConBlur(float radius) {
	radius_ = radius;
}

ConBlur::~ConBlur() {}

FloatMatrix* ConBlur::CreateKernel() {
	float width = kernel_->width();
	float height = kernel_->height();
	for(int i=0; i < kernel_->width; i++) {
		for(int j = 0; j < kernel_->height; j++) {
			float x = i - width/2;
			float y = j - height/2; 
			if (radius < 1) {
				return 1;
			}
			float distance = sqrt(x*x + y*y);
		}
	}
	
}

}  // namespace image_tools
