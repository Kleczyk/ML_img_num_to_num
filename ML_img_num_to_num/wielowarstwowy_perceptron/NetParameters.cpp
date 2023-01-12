#include "NetParameters.h"

NetParameters::NetParameters(const std::string s): path_data(s)
{
}

NetParameters::NetParameters()
{
}

void NetParameters::set_params_layers(std::vector<int> p)
{
	paramsLayers = p;
}

void NetParameters::set_larningRation(double l)
{
	larningRation = l;
}

void NetParameters::set_select_data(std::string d)
{
	select_data = d;

}

void NetParameters::set_select_Network(std::string n)
{
	select_Network = n;
}

void NetParameters::set_path_netModel(std::string n)
{
	path_netModel = n;
}

void NetParameters::set_path_data(const std::string n)
{
	new (this)NetParameters(n);
}

void NetParameters::set_pathLabel(std::string n)
{
	pathLabel = n;
}

void NetParameters::set_numEpochs(int n)
{
	numEpochs = n;
}











std::vector<int> NetParameters::get_params_layers()
{
	return paramsLayers;
}

double NetParameters::get_larningRation()
{
	return larningRation;
}

std::string NetParameters::get_select_data()
{
	return select_data;
}

std::string NetParameters::get_select_Network()
{
	return select_Network;
}

const std::string NetParameters::get_path_data() const
{
	return path_data;
}

std::string NetParameters::get_path_netModel() 
{
	return path_netModel;
}
std::string NetParameters::get_pathLabel()
{
	return pathLabel;
}


int NetParameters::get_numEpochs()
{
	return numEpochs;
}
