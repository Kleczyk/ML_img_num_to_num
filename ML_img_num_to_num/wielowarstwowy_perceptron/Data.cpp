#include "Data.h"

Data::Data()
{
	feature_vector = new std::vector<uint8_t>;
	nomalized_feature_vector = new std::vector<double>;
	class_vector = new std::vector<int>;
}

Data::~Data()
{

}

void Data::set_feature_vector(std::vector<uint8_t>* vec)
{
	feature_vector = vec;
}

void Data::set_nomalized_feature_vector(std::vector<double>* vec)
{
	nomalized_feature_vector = vec;
}

void Data::set_class_vector(int count)
{
	class_vector = new std::vector<int>;
	for (int i = 0; i < count; i++) 
	{
		if (i ==(int) label)
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

void Data::set_distance(double dis)
{
	distance = dis;
}

double Data::get_distance()
{
	return distance;
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

std::vector<double>* Data::get_nomalized_feature_vector()
{
	return nomalized_feature_vector;
}

std::vector<int>* Data::get_class_vector()
{
	return class_vector;
}

void Data::append_fvector(uint8_t val)
{
	feature_vector->push_back(val);
}

void Data::append_nomalized_fvector(double val)
{
	nomalized_feature_vector->push_back(val);
}

void Data::show_one_img()
{
	for (int i =0 ; i< feature_vector->size() ; i++)
	{
		if(i% 28==0) std::cout  << std::endl;
		std::cout << feature_vector->at(i) << " ";
		
	}
	std::cout << std::endl;
	std::cout << " ========== label: " << (int)label <<"===========" << std::endl;
	
}
