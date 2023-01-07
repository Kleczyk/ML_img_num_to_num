#pragma once
#include <fstream>
#include <vector>
#include <iostream>
#include "MNISTImage.h"
#include "stdint.h"

class Big_data
{
	std::vector<MNISTImage> vector_images;
public:
	void readMNISTImages(const std::string& fileName);
	void show();
};


