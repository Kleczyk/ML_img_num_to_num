#pragma once

#include <vector>;
#include "Data_hendler.h";
#include "Layer.h"

class NetParameters
{
protected:
	std::vector<int> paramsLayers; 
	double larningRation;
	int numEpochs;
	std::string select_data;
	std::string select_Network;
	const std::string path_data; 
	std::string pathLabel;
	std::string path_netModel;

public:
	NetParameters(const std::string);
	NetParameters();
	void set_params_layers(std::vector<int>);
	void set_larningRation(double);
	void set_select_data(std::string);
	void set_select_Network(std::string);
	void set_path_netModel(std::string);
	void set_path_data(std::string);
	void set_pathLabel(std::string);
	void set_numEpochs(int n);


	std::vector<int> get_params_layers();
	double get_larningRation();
	std::string get_select_data();
	std::string get_select_Network();
	const std::string get_path_data() const;
	std::string get_path_netModel();
	std::string get_pathLabel();
	int get_numEpochs();
	
	
};

