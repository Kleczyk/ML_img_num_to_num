#pragma once

#include "Layer.h"
#include "Data.h"
#include "Data_hendler.h"



 class InputLayer :public Layer
{
public:
	InputLayer(int prev, int current) : Layer(prev, current) {};
	//-------seters--------
	void set_layer_outputs(std::vector<double*> d );
		


};

