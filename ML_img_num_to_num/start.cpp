#include "Data.h"
#include "Data_hendler.h"
#include "CSV_data_handler.h"
#include "MNIST_data_handler.h"
#include "Big_data.h"
#include "Neuron.h"
#include "NeuronNetwork.h"
#include <locale.h>
int main()
{
    setlocale(LC_CTYPE, "Polish");
	Data_hendler *d;
	MNIST_data_handler m;
	CSV_data_handler c;


	d = &m;
	d->read_feature_vector("d:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\data\\train-images-idx3-ubyte");
	d->read_feature_labels("d:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\data\\train-labels.idx1-ubyte");
    d->make_nomalized_data();
    d->split_data();
	d->count_classes();


	/*d->read_feature_vector("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-images-idx3-ubyte.bin");
	d->read_feature_labels("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-labels.idx1-ubyte");
	d->split_data();*/




    std::vector<int> hiddenLayers = { 200,  };

    const int numEpochs = 15;
    NeuronNetwork* net = new NeuronNetwork(
        hiddenLayers,
        d->get_trening_data()->at(0)->get_nomalized_feature_vector()->size(),
        d->get_num_class(),
        0.4);
    
   
  
    net->showNetParms();
   

    net->set_trening_data(d->get_trening_data());
    net->set_test_data(d->get_test_data());
    net->set_validaction_data(d->get_validaction_data());



    net->train(numEpochs);
    std::cout << "Dopasowanie danych validacyjnych na pozomie" << net->validate() << std::endl;
    std::cout << "Dopasowanie danych tesowych na pozomie" << net->test() << std::endl;
    
 


}
