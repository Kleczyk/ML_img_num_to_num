
#include "NeuronNetwork.h"



int main()
{
    setlocale(LC_CTYPE, "Polish");


	Data_hendler *d;// stworzenie uchwytu do danych
	MNIST_data_handler m;
	CSV_data_handler c;


	d = &m;// wskaŸnik polimorficzny pokazuje ze bêd¹ to dane Mnist
	d->read_feature_vector("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-images-idx3-ubyte.bin");//odczyt i zapis danych (obrazków)
	d->read_feature_labels("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-labels.idx1-ubyte");// dopisanie do obrazków etykiet 
    d->make_nomalized_data();// normalizacja danych
    d->split_data(0.2,0.1,0.1);//podziaa³ daniych na treningowe testowe walidacyjne jako paramatry ustalamy jaka czêœæ dancy ma zostaæ przydzielona ka¿dym danym z osobna
	d->count_classes();// sprawdzanie ile mamy ró¿nych klas/ 


    //za pomoc¹wektora definiujemy iloœæ warstw oraz neuronów w tych warstwach.
    //Np.{392,100, 50} oznacza ¿e powstanie sieæ z 4 warstwami (nie liczê warstwy wejœciowej) 
    //kolejno warsty ukryte bêd¹ posiada³y 392, 100, 50 ,(liczba klas tutaj bêdize 10) liczba klas neuronów 
    std::vector<int> hiddenLayers = { 100, 30 };


    NeuronNetwork* net = new NeuronNetwork(
        hiddenLayers,//wymiary sieci 
        d->get_trening_data()->at(0)->get_nomalized_feature_vector()->size(),//iloœæ danych wejœciowych(pixeli na jednym obrazku)
        d->get_num_class(),//iloœæ ró¿nych klass


        // minimalna d³ugoœæ gradientu u¿ywana do zmniejszenia szansy wejœcia w mnimum lokalne oraz przyspieszenia zmiany w miejsch "p³askich " gdzie gradient przyjmowa³ by bardzo ma³e wartoœci 
        0.1);


    net->set_trening_data(d->get_trening_data());//wskaznie danych treningowych 
    net->set_test_data(d->get_test_data());//wskaznie danych testowych 
    net->set_validaction_data(d->get_validaction_data());//wskaznie danych validacyjnych 
    
    net->train(5);//rozpoczêcie treningu podejemy liczbê epok
    std::cout << "validation performace" << net->validate() << std::endl;
    std::cout << "test performance " << net->test() << std::endl;// test sieci na danych testowych



  
    net->fitRandom(d, 10); // pokazanie nie u¿ywanych wczeœniej obrazków z etykietami i porówanie dopasowanych wartoœci 
  


      
 


}
