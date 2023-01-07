#pragma once

#include "Data.h"
#include <vector>

class CommonData
{
protected:
	std::vector<Data*>* data_array;
	std::vector<Data*>* trening_data;		//vektor wskaŸników na dane po u¿ysciu funkcji split_data()
	std::vector<Data*>* test_data;			//vektor wskaŸników na dane po u¿ysciu funkcji split_data()
	std::vector<Data*>* validaction_data;	//vektor wskaŸników na dane po u¿ysciu funkcji split_data()
public:
	void set_trening_data(std::vector<Data*> *vec);
	void set_test_data(std::vector<Data*> *vec);
	void set_validaction_data(std::vector<Data*> *vec);



};

