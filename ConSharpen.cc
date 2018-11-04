//
// ConSharpen.cc
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
#include "flashphoto/ConSharpen.h"

namespace image_tools {
	
ConSharpen::ConSharpen(){}

ConSharpen::~ConSharpen(){}

FloatMatrix* ConSharpen::CreateKernel(){}

}  // namespace image_tools