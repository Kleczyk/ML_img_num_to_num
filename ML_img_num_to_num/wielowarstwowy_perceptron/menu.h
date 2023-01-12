#pragma once
#include "Data.h"
#include "Data_hendler.h"
#include "CSV_data_handler.h"
#include "MNIST_data_handler.h"
#include "Neuron.h"
#include "NeuronNetwork.h"
#include "NetParameters.h"
#include <clocale>
#include <thread>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <string>
#include <conio.h>

class menu
{
protected:
	// not yet
public:
	void heloInformaction();
	void selectNet(NetParameters* Net);
	void selectData(NetParameters* par);
	void select_learned_Net(NetParameters* par);
	void one_img(NetParameters* par);
	void start_menu(NetParameters* parameters);
	int main_loop();
	void drow_heder();

	friend void startNetwork(NetParameters* par);


};

