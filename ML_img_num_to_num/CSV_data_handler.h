#pragma once
#include "Data_hendler.h"
class CSV_data_handler : public Data_hendler
{
private:
	std::map<std::string, int> csv_map_class;

public:

	CSV_data_handler();
	~CSV_data_handler();

	void read_feature_vector(const std::string& path);
	

};

