#pragma once
#include <cmath>
#include <vector>
#include <random>


class Neuron
{
    
public:
    double output;
    double delta;
    std::vector<double> weights;
    Neuron(int, int);
    void init_Weights(int);
   



//	std::vector<double>  weights;  
//	double pre_activation;
//	double activated_output;
//	double output_derivative;
//	double error; 
//	double alpha;
//
//public:
//	Neuron(int, int);
//	~Neuron();
//
//	void init_weight(int prev_layer_size, int crrent_layer_size);
//	double calc_pre_activation(std::vector<double>);
//	double activation();
//	double calc_output_derivative();
//	double sigmoid();
//	double relu();
//	double leaky_relu();
//	double inverse_sqrtRelu();
//
//	//-------geters-------//
//	double get_output();
//	double get_pre_activation();
//	double get_activated_output();
//	double get_output_derivative();
//	double get_error();
//	double get_alpha();
//	std::vector<double> get_weights();
//	//--------------------//
//
//	//------seters--------//
//	void set_error(double);
//	void set_weight(double, int);
//	//--------------------//
//	 



};

