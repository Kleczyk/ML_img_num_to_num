#pragma once
#include "Layer.h"
#include "Data.h"

class OutputLayer : public Layer
{
public:
	OutputLayer(int prev, int current) : Layer(prev, current) {};
	void feed_forward(Layer prev);
	void back_wrop(Data *data);
	void update_weights(double, Layer*);
	
};

