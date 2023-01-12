#include "CommonData.h"

void CommonData::set_trening_data(std::vector<Data*> *vec)
{
	trening_data = vec;
}

void CommonData::set_test_data(std::vector<Data*> *vec)
{
	test_data = vec;
}

void CommonData::set_validaction_data(std::vector<Data*> *vec)
{
	validaction_data = vec;
}
