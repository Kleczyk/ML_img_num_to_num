#include "Data_hendler.h"
#pragma warning(disable : 4996)

Data_hendler::Data_hendler():feature_vector_size(0),num_class(10)
{
	data_array = new std::vector<Data*>;
	test_data = new std::vector<Data*>;
	trening_data = new std::vector<Data*>;
	validaction_data = new std::vector<Data*>;

}

Data_hendler::~Data_hendler()
{
	/*delete[] data_array;
	delete[] test_data;
	delete[] trening_data;
	delete[] validaction_data;*/
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

int Data_hendler::generate_random_number(int lowerBound, int upperBound)
{
	std::random_device rd;  // Use a random device to seed the generator
	std::mt19937 gen(rd());  // Use the Mersenne Twister as the generator
	std::uniform_int_distribution<> dis(lowerBound, upperBound);  // Define the range

	return dis(gen);  // Generate and return a random number
}

void Data_hendler::make_nomalized_data()
{
	std::vector<double> minV, maxV;

	Data* d = data_array->at(0);

	for (auto val : *d->get_feature_vector())
	{
		minV.push_back(val);
		maxV.push_back(val);

	}

	for (int i = 0; i < data_array->size(); i++)
	{
		d = data_array->at(i);
		for (int j = 0; j < d->get_feature_vector_size(); j++)
		{
			double val = (double)d->get_feature_vector()->at(j);
			if (val < minV.at(j)) minV.at(j) = val;
			if (val > maxV.at(j)) maxV.at(j) = val;
		}

	}
	for (int i = 0; i < data_array->size(); i++)
	{
		data_array->at(i)->set_nomalized_feature_vector(new std::vector<double>);
		data_array->at(i)->set_class_vector(num_class);
		for (int j = 0 ; j < data_array->at(i)->get_feature_vector_size(); j++)
		{
			if (maxV.at(j) - minV.at(j) == 0) data_array->at(i)->append_nomalized_fvector(0.0);
			else
			{
				data_array->at(i)->append_nomalized_fvector(
				(double)(data_array->at(i)->get_feature_vector()->at(j) - minV.at(j)) / (maxV.at(j) - minV.at(j)));
			}
		}

	}

}




