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

void Data_hendler::read_feature_vector(const std::string& path)
{
	std::ifstream file(path, std::ios::binary);


	if (!file.is_open())
	{
		std::cerr << "Failed to open file: " << path << std::endl;
		exit(1);
	}

	//reading header ifnormaction
	uint32_t header_of_file[4];
	//heder[0] 32 bit integer  0x00000803(2051) magic number
	//heder[1] 32 bit integer  60000            number of images
	//heder[2] 32 bit integer  28               number of rows
	//headr[3] 32 bit integer  28               number of columns

	unsigned char word[4];
	for (int i = 0; i < 4; i++)
	{
		if (file)
		{
			file.read((char*)word, sizeof(word));
			header_of_file[i] = convert_to_little_endian(word);
		}
		else
		{
			std::cerr << " wrong read for file with img" << std::endl;
			exit(1);
		}
	}
	std::cout << "sucessfull read and store heder data" << std::endl;
	if (header_of_file[0] != 0x803)
	{
		std::cerr << "Invalid magic number: " << header_of_file[0] << std::endl;
		exit(1);
	}
	/*std::cout << header_of_file[0] << std::endl;
	std::cout << header_of_file[1] << std::endl;
	std::cout << header_of_file[2] << std::endl;
	std::cout << header_of_file[3] << std::endl;*/

	// reading pixel's img

	int img_size = header_of_file[2] * header_of_file[3];

	for (int i = 0; i < header_of_file[1]; i++)
	{
		uint8_t pixel;
		unsigned char pixel_char = 0;
		Data* d = new Data;

		for (int j = 0; j < img_size; j++)
		{
			if (file)
			{
				file.read((char*)&pixel_char, sizeof(pixel_char));
				pixel = (uint8_t)pixel_char;
				d->append_fvector(pixel);
			}
			else
			{
				std::cerr << " wrong read for file with img " << std::endl;
				exit(1);
			}
		}
		data_array->push_back(d); //dodaenie obrazka na koniec zbioru obrazków(data_array)
	}
	std::cout << "sucessfull read and store pixl of img, " << data_array->size() << " imges" << std::endl;

	
} //odczytuje z pliku liczbê rozmiar zdj i wartoœci poszczególnych pikseli i  tworzy obiekty typu Data uzupie³niaj¹c jest danymi

void Data_hendler::read_feature_labels(std::string path)
{
	std::ifstream file(path, std::ios::binary);


	if (!file.is_open())
	{
		std::cerr << "Failed to open file: " << path << std::endl;
		exit(1);
	}

	//reading header ifnormaction
	uint32_t header_of_file[2];
	//heder[0] 32 bit integer  0x00000803(2051) magic number
	//heder[1] 32 bit integer  60000            number of images
	
	unsigned char word[4];
	for (int i = 0; i < 2; i++)
	{
		if (file)
		{
			file.read((char*)word, sizeof(word));
			header_of_file[i] = convert_to_little_endian(word);
		}
		else
		{
			std::cerr << " wrong read for file with label" << std::endl;
			exit(1);
		}
	}
	std::cout << "sucessfull read and store heder label" << std::endl;
	if (header_of_file[0] != 2049)
	{
		std::cerr << "Invalid magic number: " << header_of_file[0] << std::endl;
		exit(1);
	}
	/*std::cout << header_of_file[0] << std::endl;
	std::cout << header_of_file[1] << std::endl;
	std::cout << header_of_file[2] << std::endl;
	std::cout << header_of_file[3] << std::endl;*/

	// reading label

	
	for (int i = 0; i < header_of_file[1]; i++)
	{
		uint8_t label;
		unsigned char label_char = 0;
		if (data_array != nullptr)
		{
				if (file)
				{
					file.read((char*)&label_char, sizeof(label_char));
					label = (uint8_t)label_char;
					data_array->at(i)->set_label_D(label);
				}
				else
				{
					std::cerr << " wrong read for file with labels " << std::endl;
					exit(1);
				}
			

		}
		else
		{
			std::cerr << " ivizable read img, first read img " << std::endl;
			exit(1);
		}
	}
	std::cout << "sucessfull read and store labels " << data_array->size() << " imges" << std::endl;
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
		
		int rand_index = generate_random_number(0, data_array->size()-1);
		
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
		int rand_index = generate_random_number(0, data_array->size() - 1);
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
		int rand_index = generate_random_number(0, data_array->size() - 1);
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
		if (mnist_map_class.find(data_array->at(i)->get_label()) == mnist_map_class.end())
		{
			mnist_map_class[data_array->at(i)->get_label()] = count;
			data_array->at(i)->set_enum_label(count);
			count++;
		}
		
	}
	num_class = count;
	std::cout << "successfully count class, is " << num_class << std::endl;

}

void Data_hendler::show_img()
{
	int x28 = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int r = 0; r < 28; r++)
		{
			for (int c = 0; c < 28; c++)
			{
				std::cout << data_array->at(i)->get_feature_vector()->at(c+r*28)<< "\.";

			}
			std::cout << std::endl;

		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

	}
}

void Data_hendler::read_csv(const std::string& path, std::string stop) 
{
	
	num_class = 0;
	std::ifstream file(path);
	std::string line;

	//TO DO dodaæ walidacje pliku
	while (std::getline(file, line))
	{
		if (line.length() == 0) continue;
		Data* d = new Data;
		d->set_double_feature_vector(new std::vector<double>);
		size_t position = 0;
		std::string token;
		while (position = line.find(stop) != std::string::npos)
		{
			token = line.substr(0, position);
			d->append_double_fvector(std::stod(token));
			line.erase(0, position + stop.length());

		}
		if (csv_map_class.find(line) != csv_map_class.end())
		{
			d->set_label_D(csv_map_class[line]);

		}
		else
		{
			csv_map_class[line] = num_class;
			d->set_label_D(csv_map_class[line]);
			num_class++;
		}
		data_array->push_back(d);

	}
	feature_vector_size = this->data_array->at(0)->get_double_feature_vector()->size();
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

int Data_hendler::get_num_class()
{
	return num_class;
}

int Data_hendler::get_feature_vector_size()
{
	return feature_vector_size;
}

std::map<uint8_t, int> Data_hendler::get_map_class()
{
	return mnist_map_class;
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

int Data_hendler::generate_random_number(int lowerBound, int upperBound)
{
	std::random_device rd;  // Use a random device to seed the generator
	std::mt19937 gen(rd());  // Use the Mersenne Twister as the generator
	std::uniform_int_distribution<> dis(lowerBound, upperBound);  // Define the range

	return dis(gen);  // Generate and return a random number
}


