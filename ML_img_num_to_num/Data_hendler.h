#pragma once

#include <fstream>
#include "Data.h"
#include <string>
#include <map>
#include <unordered_set>
#include <random>
 
class Data_hendler
{
	std::vector<Data*>* data_array; //wskaaŸniki na wszystkie dane
	std::vector<Data*>*	trening_data;		//vektor wskaŸników na dane po u¿ysciu funkcji split_data()
	std::vector<Data*>* test_data;			//vektor wskaŸników na dane po u¿ysciu funkcji split_data()
	std::vector<Data*>* validaction_data;	//vektor wskaŸników na dane po u¿ysciu funkcji split_data()

	int num_class;
	int feature_vector_size;
	std::map<uint8_t, int> mnist_map_class;
	std::map<std::string, int> csv_map_class;
	////TO DO dodanie podzia³u do seterów i zainicjowaæ jee w konstruktorze 
	const double TRAIN_SET_PERCENT = 0.75;
	const double TEST_SET_PERCENT = 0.20;
	const double VALIDACTION_SET_PERCENT = 0.05;
public:
	Data_hendler();
	~Data_hendler();

	// methods to read from MNIST file 
	void read_feature_vector(const std::string& path);
	void read_feature_labels(std::string path);
	void show_img();

	//methods to read fom CSV

	void read_csv(const std::string& path, std::string stop);


	////TO DO zrobie nadklasy do data_hendler
	void split_data(); 
	void count_classes();
	uint32_t convert_to_little_endian(const unsigned char* bytes);
	int generate_random_number(int lowerBound, int upperBound);
	void show_img_in_console();
	int reverseInt(int i);

	//-------geters---------//
	std::vector<Data*>* get_trening_data();
	std::vector<Data*>* get_test_data();
	std::vector<Data*>* get_validaction_data();
	int get_num_class();
	int get_feature_vector_size();
	std::map<uint8_t, int> get_map_class();
	//----------------------//
	

	

	





};

