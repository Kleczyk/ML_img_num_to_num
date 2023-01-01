#pragma once
#include<vector>
//#include "neuron.cpp"


class Layer
{
public:
	int now_layer_size;
	//std::vector<Neuron*> Neurons;
	std::vector <double> layer_output;
	Layer(int, int);
	~Layer();

	//--------Geters---------//

	std::vector<double> get_layer_output();
	int get_now_layer_output();
	//std::vevtor<neuron*> get_Neurons;

	//-----------------------//

};

