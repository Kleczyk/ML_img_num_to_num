#pragma once

#include <vector>
#include "stdint.h"
#include <iostream>

class Data
{
	std::vector<uint8_t>* feature_vector;
	std::vector<double>* nomalized_feature_vector;
	std::vector<int>* class_vector;
	uint8_t label;
	int enum_label;
	double distance; 

public:
	Data();
	~Data();
	void set_feature_vector(std::vector<uint8_t>* vec);
	void set_nomalized_feature_vector(std::vector<double>* vec);
	void set_class_vector(int count);
	void set_label_D(uint8_t lab);
	void set_enum_label(int enume_lab);
	void set_distance(double);

	double get_distance();
	int get_feature_vector_size();
	uint8_t get_label();
	int get_enum_label();
	std::vector<uint8_t>* get_feature_vector();
	std::vector<double>* get_nomalized_feature_vector();
	std::vector<int>* get_class_vector();
	void append_fvector(uint8_t val);
	void append_nomalized_fvector(double val);
	






};

