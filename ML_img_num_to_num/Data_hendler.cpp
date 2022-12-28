#include "Data_hendler.h"
#pragma warning(disable : 4996)

Data_hendler::Data_hendler():feature_vector_size(0),num_class(0)
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
		std::cout << "succesfully load begin img" << std::endl; 

		std::cout << hendler[0] << std::endl;
		std::cout << hendler[1] << std::endl;
		std::cout << hendler[2] << std::endl;
		std::cout << hendler[3] << std::endl;
		
		/*unsigned char pixel[1];

		for (int i = 0; i < 1000 ; i++)
		{
			if (fread(pixel, sizeof(pixel), 1, f))
			{
				std::cout << (int)pixel[0] << " ";
			}
		}*/
		

		int img_size= hendler[2] * hendler[3];
		for (int i = 0; i < hendler[1]; i++)
		{
			Data* d = new Data();
			uint8_t element[1];

			for (int j = 0; j < img_size ; j++)
			{
				
				if (fread(element, sizeof(element), 1, f))
				{
					d->append_fvector(element[0]);
					//std::cout << (char)element[0];
				}
				/*else
				{
					std::cout << "wrong reading form file" << std::endl;
					exit(1);
				}*/
				
				//std::cout << element[0] << std::endl;
			}
			data_array->push_back(d);
			//std::cout << i << std::endl;
		}
		std::cout << "successfully Read and store "<< data_array->size()<< "vectors " << std::endl;
	}
	else
	{
		std::cout << "this file does't exitst" << std::endl;
		exit(1);
	}
} //odczytuje z pliku liczbê rozmiar zdj i wartoœci poszczególnych pikseli i  tworzy obiekty typu Data uzupie³niaj¹c jest danymi

void Data_hendler::read_feature_labels(std::string path)
{
	uint32_t hendler[2];
	unsigned char co[4];
	FILE* f = fopen(path.c_str(), "r");
	if (f)
	{
		for (int i = 0; i < 2; i++)
		{
			if (fread(co, sizeof(co), 1, f))
			{
				hendler[i] = convert_to_little_endian(co);
			}

		}
		std::cout << "succesfully load begin label" << std::endl;
		std::cout << hendler[0] << std::endl;
		std::cout << hendler[1] << std::endl;
	
		
		for (int i = 0; i < hendler[1]; i++)
		{
			uint8_t c[1];
			if(fread( c, sizeof(c),1,f))
			{
				data_array->at(i)->set_label_D(c[0]);
			}
			/*else
			{
				std::cout << "wrong Reading form label's FILE" << std::endl;
				exit(1);
			}*/
		}
		std::cout << "successfully Read and store labels" << data_array->size() << std::endl;		
	}
	else
	{
		std::cout << "this file does't exitst" << std::endl;
		exit(1);
	}
}

void Data_hendler::split_data()
{
	std::unordered_set<int> used_indxs;
	int size_trening = data_array->size() * TRAIN_SET_PERCENT;
	int size_test = data_array->size() * TEST_SET_PERCENT;
	int size_validaction = data_array->size() * VALIDACTION_SET_PERCENT;
	 
	//trenin data
	int i = 0;
	while (i < size_trening)
	{
		int rand_index = rand() % data_array->size();
		if (used_indxs.find(rand_index) == used_indxs.end())
		{
			trening_data->push_back(data_array->at(rand_index));
			used_indxs.insert(rand_index);
			i++;
			
		}
	}
	//test data
	i = 0;
	while (i < size_test)
	{
		int rand_index = rand() % data_array->size();
		if (used_indxs.find(rand_index) == used_indxs.end())
		{
			test_data->push_back(data_array->at(rand_index));
			used_indxs.insert(rand_index);
			i++;

		}
	}

	//Validaction data
	i = 0;
	while (i < size_validaction)
	{
		int rand_index = rand() % data_array->size();
		if (used_indxs.find(rand_index) == used_indxs.end())
		{
			validaction_data->push_back(data_array->at(rand_index));
			used_indxs.insert(rand_index);
			i++;

		}
	}
	std::cout << "size of trening data " << trening_data->size() << std::endl;
	std::cout << "size of test data " << test_data->size() << std::endl;
	std::cout << "size of validaction data " << validaction_data->size() << std::endl;


}

void Data_hendler::count_classes()
{
	int count = 0;

	for (unsigned i = 0; i < data_array->size(); i++)
	{
		if (map_class.find(data_array->at(i)->get_label()) == map_class.end())
		{
			map_class[data_array->at(i)->get_label()] = count;
			data_array->at(i)->set_enum_label(count);
			count++;
		}
		
	}
	num_class = count;
	std::cout << "successfully count class, is " << num_class << std::endl;

}

uint32_t Data_hendler::convert_to_little_endian(const unsigned char* bytes)
{
	return (uint32_t)((bytes[0] << 24) |
						(bytes[1] << 16) |
						(bytes[2] << 8) |
						(bytes[3]));
}

std::vector<Data*>* Data_hendler::get_trening_data()
{
	
	return trening_data;
}

std::vector<Data*>* Data_hendler::get_test_data()
{
	return test_data;
}

std::vector<Data*>* Data_hendler::get_validaction_data()
{
	return validaction_data;
}

void Data_hendler::show_img_in_console()
{
	int x28=0;
	for (int i = 0; i < 28; i++) 
	{
		
		for (int j = 0; j < 28; j++)
		{
			uint8_t t = data_array->at(0)->get_feature_vector()->at(j+x28);
			std::cout << t<< "O";
		}
		x28 += 28;
		std::cout << std::endl;
	}
	
}


int Data_hendler::reverseInt(int i)
{
	unsigned char c1, c2, c3, c4;

	c1 = i & 255;
	c2 = (i >> 8) & 255;
	c3 = (i >> 16) & 255;
	c4 = (i >> 24) & 255;

	return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
}
void Data_hendler::read_mnist(std::string path)
{
	std::ifstream file(path.c_str());
	if (file.is_open())
	{
		int magic_number = 0;
		int number_of_images = 0;
		int n_rows = 0;
		int n_cols = 0;
		file.read((char*)&magic_number, sizeof(magic_number));
		magic_number = reverseInt(magic_number);
		file.read((char*)&number_of_images, sizeof(number_of_images));
		number_of_images = reverseInt(number_of_images);
		file.read((char*)&n_rows, sizeof(n_rows));
		n_rows = reverseInt(n_rows);
		file.read((char*)&n_cols, sizeof(n_cols));
		n_cols = reverseInt(n_cols);
		for (int i = 0; i < number_of_images; ++i)
		{
			for (int r = 0; r < n_rows; ++r)
			{
				for (int c = 0; c < n_cols; ++c)
				{
					unsigned char temp = 0;
					file.read((char*)&temp, sizeof(temp));
					std::cout << temp;

				}
			}
		}
		std::cout << "1";
	}
}

