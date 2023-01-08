#pragma once
#include "Data.h"
#include "Data_hendler.h"
#include "CommonData.h"
#include "Layer.h"
#include "InputLayer.h"
#include "HiddenLayer.h"
#include "OutputLayer.h"
#include <numeric>

class NeuronNetwork : public CommonData
{


public:
    std::vector<Layer*> layers;
    double learningRate;
    double testPerformance;
    NeuronNetwork(std::vector<int> , int, int, double);
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
    double validate();
    


};

 