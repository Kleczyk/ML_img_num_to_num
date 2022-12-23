#include "Data_hendler.h"

Data_hendler::Data_hendler()
{
	data_array = new std::vector<Data*>;
	test_data = new std::vector<Data*>;
	trening_data = new std::vector<Data*>;
	validaction_data = new std::vector<Data*>;

}

Data_hendler::~Data_hendler()
{
	delete[] data_array;
	delete[] test_data;
	delete[] trening_data;
	delete[] validaction_data;
}

void Data_hendler::read_feature_vector(std::string path)
{
}

void Data_hendler::read_feature_labels(std::string path)
{
}

void Data_hendler::split_data()
{
}

void Data_hendler::count_classes()
{
}

uint32_t Data_hendler::convert_to_little_endian(const unsigned char* bytes)
{
	return uint32_t();
}

std::vector<Data*>* Data_hendler::get_trening_data()
{
	return nullptr;
}

std::vector<Data*>* Data_hendler::get_test_data()
{
	return nullptr;
}

std::vector<Data*>* Data_hendler::get_validaction_data()
{
	return nullptr;
}
