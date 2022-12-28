#include "Data.h"
#include "Data_hendler.h"
int main()
{
	Data_hendler* dh = new Data_hendler();

	dh->read_feature_vector("D:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\t10k-images.idx3-ubyte");
	dh->read_feature_labels("D:\\prz\\sem_3\\C++\\czy_to_sie_uda\\ML_i_num_to_num\\t10k-labels.idx1-ubyte");
	dh->split_data();
	dh->count_classes();
}
