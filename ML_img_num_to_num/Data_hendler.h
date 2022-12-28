#pragma once

#include <fstream>
#include "Data.h"
#include <string>
#include <map>
#include <unordered_set>
 
class Data_hendler
{
	std::vector<Data*>* data_array; //wskaaüniki na wszystkie dane
	std::vector<Data*>*	trening_data;
	std::vector<Data*>* test_data;
	std::vector<Data*>* validaction_data;

	int num_class;
	int feature_vector_size;
	std::map<uint8_t, int> map_class;

	const double TRAIN_SET_PERCENT = 0.75;
	const double TEST_SET_PERCENT = 0.20;
	const double VALIDACTION_SET_PERCENT = 0.05;
public:
	Data_hendler();
	~Data_hendler();

	void read_feature_vector(std::string path);
	void read_feature_labels(std::string path);
	void split_data(); 
	void count_classes();

	uint32_t convert_to_little_endian(const unsigned char* bytes);

	std::vector<Data*>* get_trening_data();
	std::vector<Data*>* get_test_data();
	std::vector<Data*>* get_validaction_data();

	void show_img_in_console();

	int reverseInt(int i);

	void read_mnist(std::string path);





};

