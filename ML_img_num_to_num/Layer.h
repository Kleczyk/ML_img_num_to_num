#pragma once
#include<vector>
#include "Neuron.h"


class Layer
{


public:
    int currentLayerSize;
    std::vector<Neuron*> neurons;
    std::vector<double> layerOutputs;
    Layer(int, int);

//public:
//	int now_layer_size;
//	//std::vector<Neuron*> Neurons;
//	std::vector <double> layer_output;
//	Layer(int, int);
//	~Layer();
//
//	//--------Geters---------//
//
//	std::vector<double> get_layer_output();
//	int get_now_layer_output();
//	//std::vevtor<neuron*> get_Neurons;
//
//	//-----------------------//

};

