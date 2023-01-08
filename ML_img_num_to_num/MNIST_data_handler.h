#pragma once
#include "Data_hendler.h"

class MNIST_data_handler : public Data_hendler
{
private:
	std::map<uint8_t, int> map_class;

	

public:
	MNIST_data_handler();
	~MNIST_data_handler();

	void read_feature_vector(const std::string& path) ;
	void read_feature_labels(std::string path) ;
	void count_classes();
	std::map<uint8_t, int> get_map_class();
	uint32_t convert_to_little_endian(const unsigned char* bytes);


};

