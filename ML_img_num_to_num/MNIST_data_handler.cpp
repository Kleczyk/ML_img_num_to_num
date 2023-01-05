#include "MNIST_data_handler.h"

MNIST_data_handler::~MNIST_data_handler()
{
	delete[] data_array;
	delete[] test_data;
	delete[] trening_data;
	delete[] validaction_data;
}

void MNIST_data_handler::read_feature_vector(const std::string& path)
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


}

void MNIST_data_handler::read_feature_labels(std::string path)
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

void MNIST_data_handler::count_classes()
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

std::map<uint8_t, int> MNIST_data_handler::get_map_class()
{
	return map_class;
}

uint32_t MNIST_data_handler::convert_to_little_endian(const unsigned char* bytes)
{
	return (uint32_t)((bytes[0] << 24) |
		(bytes[1] << 16) |
		(bytes[2] << 8) |
		(bytes[3]));
}

