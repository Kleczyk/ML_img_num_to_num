#pragma once
#include "Layer.h"

class HiddenLayer : public Layer
{
public:
	HiddenLayer(int prev, int current) : Layer(prev, current) {};
	void feed_forward(Layer prev);
	void back_prop(Layer next);
	void update_weights(double, Layer*);
};

