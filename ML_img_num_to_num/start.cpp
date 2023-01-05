#include "Data.h"
#include "Data_hendler.h"
#include "CSV_data_handler.h"
#include "MNIST_data_handler.h"
#include "Big_data.h"
#include "Neuron.h"
#include "NeuronNetwork.h"
int main()
{
	Data_hendler *d;
	MNIST_data_handler m;
	CSV_data_handler c;


	d = &m;
	d->read_feature_vector("D:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\train-images-idx3-ubyte.bin");
	d->read_feature_labels("D:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\train-labels.idx1-ubyte");

	/*d->read_feature_vector("D:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\train-images-idx3-ubyte.bin");
	d->read_feature_labels("D:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\train-labels.idx1-ubyte");
	d->split_data();*/


}
