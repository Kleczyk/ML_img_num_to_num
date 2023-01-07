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
	d->read_feature_vector("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-images-idx3-ubyte.bin");
	d->read_feature_labels("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-labels.idx1-ubyte");
    d->make_nomalized_data();
    d->split_data();
	d->count_classes();
    

	/*d->read_feature_vector("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-images-idx3-ubyte.bin");
	d->read_feature_labels("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-labels.idx1-ubyte");
	d->split_data();*/




    std::vector<int> hiddenLayers = { 3};

        NeuronNetwork* net = new NeuronNetwork(
            hiddenLayers,
            d->get_trening_data()->at(0)->get_nomalized_feature_vector()->size(),
            d->get_num_class(),
            0.3);
        net->set_trening_data(d->get_trening_data());
        net->set_test_data(d->get_test_data());
        net->set_validaction_data(d->get_validaction_data());
        net->train(5);
        net->validate();
        printf("Test Performance: %.3f\n", net->test());
 


}
