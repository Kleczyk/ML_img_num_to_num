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

void Data::set_double_feature_vector(std::vector<double>* vec)
{
	double_feature_vector = vec;
}

void Data::set_class_vector(int count)
{
	class_vector = new std::vector<int>;
	for (int i = 0; i < count; i++) 
	{
		if (i == label)
		{
			class_vector->push_back(1);

		}
		else
		{
			class_vector->push_back(0);
		}
	}
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

std::vector<double>* Data::get_double_feature_vector()
{
	return nullptr;
}

std::vector<int>* Data::get_class_vector()
{
	return nullptr;
}

void Data::append_fvector(uint8_t val)
{
	feature_vector->push_back(val);
}

void Data::append_double_fvector(double val)
{
	double_feature_vector->push_back(val);
}
