
#include "NeuronNetwork.h"



int main()
{
    setlocale(LC_CTYPE, "Polish");


	Data_hendler *d;// stworzenie uchwytu do danych
	MNIST_data_handler m;
	CSV_data_handler c;


	d = &m;// wska�nik polimorficzny pokazuje ze b�d� to dane Mnist
	d->read_feature_vector("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-images-idx3-ubyte.bin");//odczyt i zapis danych (obrazk�w)
	d->read_feature_labels("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-labels.idx1-ubyte");// dopisanie do obrazk�w etykiet 
    d->make_nomalized_data();// normalizacja danych
    d->split_data(0.2,0.1,0.1);//podziaa� daniych na treningowe testowe walidacyjne jako paramatry ustalamy jaka cz�� dancy ma zosta� przydzielona ka�dym danym z osobna
	d->count_classes();// sprawdzanie ile mamy r�nych klas/ 


    //za pomoc�wektora definiujemy ilo�� warstw oraz neuron�w w tych warstwach.
    //Np.{392,100, 50} oznacza �e powstanie sie� z 4 warstwami (nie licz� warstwy wej�ciowej) 
    //kolejno warsty ukryte b�d� posiada�y 392, 100, 50 ,(liczba klas tutaj b�dize 10) liczba klas neuron�w 
    std::vector<int> hiddenLayers = { 100, 30 };


    NeuronNetwork* net = new NeuronNetwork(
        hiddenLayers,//wymiary sieci 
        d->get_trening_data()->at(0)->get_nomalized_feature_vector()->size(),//ilo�� danych wej�ciowych(pixeli na jednym obrazku)
        d->get_num_class(),//ilo�� r�nych klass


        // minimalna d�ugo�� gradientu u�ywana do zmniejszenia szansy wej�cia w mnimum lokalne oraz przyspieszenia zmiany w miejsch "p�askich " gdzie gradient przyjmowa� by bardzo ma�e warto�ci 
        0.1);


    net->set_trening_data(d->get_trening_data());//wskaznie danych treningowych 
    net->set_test_data(d->get_test_data());//wskaznie danych testowych 
    net->set_validaction_data(d->get_validaction_data());//wskaznie danych validacyjnych 
    
    net->train(5);//rozpocz�cie treningu podejemy liczb� epok
    std::cout << "validation performace" << net->validate() << std::endl;
    std::cout << "test performance " << net->test() << std::endl;// test sieci na danych testowych



  
    net->fitRandom(d, 10); // pokazanie nie u�ywanych wcze�niej obrazk�w z etykietami i por�wanie dopasowanych warto�ci 
  


      
 


}
