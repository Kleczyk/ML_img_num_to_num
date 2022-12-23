#include "Data.h"

Data::Data()
{
	feature_vector = new std::vector<uint8_t>;

}

Data::~Data()
{

}

void Data::set_feature_vector(std::vector<uint8_t>* vec)
{
	feature_vector = vec;
}

void Data::set_label_D(uint8_t lab)
{
	label = lab;
}

void Data::set_enum_label(int enume_lab)
{
	enum_label = enume_lab;
}

int Data::get_feature_vector_size()
{
	return (int)feature_vector->size();
}

uint8_t Data::get_label()
{
	return label;
}

int Data::get_enum_label()
{
	return enum_label;
}

std::vector<uint8_t>* Data::get_feature_vector()
{
	return feature_vector;
}

void Data::append_fvector(uint8_t val)
{
	feature_vector->push_back(val);
}
