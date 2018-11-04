//
// ConvolutionFilter.cc
//
// Created by Zeyu Gao on 10/25/2018
// Copyright (c) 2018 Zeyu Gao. All rights reserved. 
//

#include "flashphoto/ConvolutionFilter.h"
#include <string>
#include "flashphoto/filter.h"
#include "flashphoto/color_data.h"
#include "flashphoto/pixel_buffer.h"
#include "flashphoto/mask_factory.h"
#include "flashphoto/float_matrix.h"
#include "flashphoto/image_tools_math.h"
#include <cmath>


namespace image_tools {

ConvolutionFilter::ConvolutionFilter(FloatMatrix* Kernel) {
	Kernel_ = Kernel; 
	
	
}

ConvolutionFilter::~ConvolutionFilter(){}


void ConvolutionFilter::SetupFilter(){
	CreateKernel();
}

ColorData ConvolutionFilter::CalculateFilteredPixel(PixelBuffer* buffer, int x, int y){
	ColorData color = buffer->pixel(x,y); // Get buffer pixel
	ColorData outputcolor(0,0,0,0);
	//ColorData black = ColorData(0,0,0); // color black
	//ColorData white = ColorData(255,255,255); // color white 
	
	int width = kernel_->width(); //kernel width 
	int height = kernel_->height(); // kernel height 
	
	//int width2 = kernel_->width()/2; // halff kernelwidth
	//int height2 = kernel_->height()/2; // halff kernel height
	
	int kernelw = buffer->width(); //buffer width 
	int kernelh = buffer->height(); //buffer height 
	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			int center_pt_of_x = x + i - (width/2); 
			int center_pt_of_y = y + j - (height/2);
			center_pt_of_x = ImageToolsMath::clamp(center_pt_of_x, 0, kernelw - 1);
			center_pt_of_y = ImageToolsMath::clamp(center_pt_of_y, 0, kernelh - 1);
			
			ColorData center = buffer->pixel(center_pt_of_x, center_pt_of_y);
			float newalpha_ = center.alpha();
			ColorData bolder = center * newalpha_;
			bolder.alpha(newalpha_);
			ColorData degree = bolder * kernel_->value(i,j);
			degree.alpha(newalpha_);
			outputcolor += degree; 
		}
	}
	
	return outputcolor; 
}

void ConvolutionFilter::CleanupFilter() {
	sdelete CreateKernel();
}

bool ConvolutionFilter::can_calculate_in_place() {
	return false;
}

}  // namespace image_tools
