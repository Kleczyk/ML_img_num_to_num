#pragma once
#include "Data.h"
#include "Data_hendler.h"
#include "CommonData.h"
#include "Layer.h"
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"

class NeuronNetwork : public CommonData
{


public:
    std::vector<Layer*> layers;
    double learningRate;
    double testPerformance;
    NeuronNetwork(std::vector<int> spec, int, int, double);
    ~NeuronNetwork();
    std::vector<double> fprop(Data* data);
    double activate(std::vector<double>, std::vector<double>); // dot product
    double transfer(double);
    double transferDerivative(double); // used for backprop
    void bprop(Data* data);
    void updateWeights(Data* data);
    int predict(Data* data); // return the index of the maximum value in the output array.
    void train(int); // num iterations
    double test();
    void validate();

//private:
//	InputLayer* input_layer;
//	OutputLayer* output_layer;
//	std::vector<HiddenLayer*> hidden_layers;
//	double eta;
//
//public:
//	NeuronNetwork(std::vector<int> hidden_layer_Spec, int, int);
//	~NeuronNetwork();
//	void forward_prop(Data *data);
//	void back_prop(Data* data);
//	void update_weights();
//	void trein();
//	void test();
//	void validaction();
};

 