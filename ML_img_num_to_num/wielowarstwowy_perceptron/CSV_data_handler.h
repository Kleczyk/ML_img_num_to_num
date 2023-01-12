#pragma once
#include "Data_hendler.h"
class CSV_data_handler : public Data_hendler
{
private:
	std::map<std::string, int> map_class;

public:

	CSV_data_handler();
	~CSV_data_handler();

	void read_feature_vector(const std::string& path) override; // zle 
	void read_feature_labels(std::string path);
	void count_classes();

	std::map<std::string, int> get_map_class();
};

