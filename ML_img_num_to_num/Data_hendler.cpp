#include "Data_hendler.h"
#pragma warning(disable : 4996)

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

void Data_hendler::read_feature_vector(const std::string path)
{
	uint32_t hendler[4];
	unsigned char co[4];
	FILE *f = fopen(path.c_str(), "r");
	if (f)
	{
		for (int i = 0; i < 4; i++)
		{
			if (fread(co, sizeof(co), 1, f))
			{
				hendler[i] = convert_to_little_endian(co);
			}

		}
		std::cout << "succesfull load label" << std::endl; 
		int img_size= hendler[2] * hendler[3];
		for (int i = 0; i < (int)hendler[1]; i++)
		{
			Data* d = new Data();
			uint8_t element[1];
			for (int j = 0; j < img_size; j++)
			{
				if (fread(element, sizeof(element), 1, f))
				{
					d->append_fvector(element[0]);

				}
				else
				{
					std::cout << "wrong Reading form FILE" << std::endl;
					exit(1);
				}
			}
		}
		std::cout << "successfully Read and store "<< data_array->size()<< "vectors " << std::endl;
	}
	else
	{
		std::cout << "this file does't exitst" << std::endl;
		exit(1);
	}
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
