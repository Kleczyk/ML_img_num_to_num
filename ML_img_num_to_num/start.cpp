#include "Data.h"
#include "Data_hendler.h"
#include "Big_data.h"
#include "Neuron.h"
#include "NeuronNetwork.h"
int main()
{
	/*Data_hendler* dh = new Data_hendler();
	dh->read_feature_vector("D:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\train-images-idx3-ubyte.bin");
	dh->read_feature_labels("D:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\train-labels.idx1-ubyte");
	dh->split_data();
	dh->count_classes();
	dh->show_img();*/


    /*Data_hendler* dataHandler = new Data_hendler();
#ifdef MNIST
    dataHandler->readInputData("../train-images-idx3-ubyte");
    dataHandler->readLabelData("../train-labels-idx1-ubyte");
    dataHandler->countClasses();
#else
    dataHandler->read_csv("../iris.data", ",");
#endif
    dataHandler->split_data();
    std::vector<int> hiddenLayers = { 10 };
    auto lambda = [&]() {
        NeuronNetwork* net = new NeuronNetwork(
            hiddenLayers,
            dataHandler->get_trening_data()->at(0)->getNormalizedFeatureVector()->size(),
            dataHandler->get_num_class(),
            0.25);
        net->set_trening_data(dataHandler->get_trening_data());
        net->set_test_data(dataHandler->get_test_data());
        net->set_validaction_data(dataHandler->get_validaction_data());
        net->train(15);
        net->validate();
        printf("Test Performance: %.3f\n", net->test());
    };
    lambda();*/

}
