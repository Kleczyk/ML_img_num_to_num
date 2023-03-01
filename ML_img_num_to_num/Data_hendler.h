#pragma once

#include <fstream>
#include "Data.h"
#include <string>
#include <map>
#include <unordered_set>
#include <random>
 
class Data_hendler
{
protected:
	std::vector<Data*>* data_array; //wskaaŸniki na wszystkie dane
	std::vector<Data*>*	trening_data;		//vektor wskaŸników na dane po u¿ysciu funkcji split_data()
	std::vector<Data*>* test_data;			//vektor wskaŸników na dane po u¿ysciu funkcji split_data()
	std::vector<Data*>* validaction_data;	//vektor wskaŸników na dane po u¿ysciu funkcji split_data()

	int num_class;
	int feature_vector_size;
public:
	Data_hendler();
	~Data_hendler();
	virtual void read_feature_vector(const std::string& path)=0;
	virtual void read_feature_labels(std::string path)=0;
	virtual void count_classes()=0;
	void split_data(double, double, double);
	void show_img();
	int generate_random_number(int lowerBound, int upperBound);
	void make_nomalized_data();
	

	//-------geters---------//
	std::vector<Data*>* get_trening_data();
	std::vector<Data*>* get_test_data();
	std::vector<Data*>* get_validaction_data();
	int get_num_class();
	int get_feature_vector_size();
	
	//----------------------//
	

	

	





};

