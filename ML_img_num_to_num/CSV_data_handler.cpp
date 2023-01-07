#include "CSV_data_handler.h"

CSV_data_handler::CSV_data_handler()
{
}

CSV_data_handler::~CSV_data_handler()
{
	/*delete[] data_array;
	delete[] test_data;
	delete[] trening_data;
	delete[] validaction_data;*/
}

void CSV_data_handler::read_feature_vector(const std::string& path)
{
	//num_class = 0;
	//std::ifstream file(path);
	//std::string line;

	////TO DO dodaæ walidacje pliku
	//while (std::getline(file, line))
	//{
	//	if (line.length() == 0) continue;
	//	Data* d = new Data;
	//	d->set_double_feature_vector(new std::vector<double>);
	//	size_t position = 0;
	//	std::string token;
	//	while (position = line.find(stop) != std::string::npos)
	//	{
	//		token = line.substr(0, position);
	//		d->append_double_fvector(std::stod(token));
	//		line.erase(0, position + stop.length());

	//	}
	//	if (map_class.find(line) != map_class.end())
	//	{
	//		d->set_label_D(map_class[line]);

	//	}
	//	else
	//	{
	//		map_class[line] = num_class;
	//		d->set_label_D(map_class[line]);
	//		num_class++;
	//	}
	//	data_array->push_back(d);

	//}
	//feature_vector_size = this->data_array->at(0)->get_double_feature_vector()->size();
}

void CSV_data_handler::read_feature_labels(std::string path)
{
	1; 
}

void CSV_data_handler::count_classes()
{
	1;
}

std::map<std::string, int> CSV_data_handler::get_map_class()
{
	return std::map<std::string, int>();
}
