#include "menu.h"
#include <conio.h>

Data_hendler* prepare_data(const std::string path, std::string path2);
void startNetwork(NetParameters* par);

void menu::heloInformaction()
{
    std::cout << "=========================================================================" << std::endl; 
    std::cout << "Witaj jest to program implementuj¹cy i obs³uguj¹cy g³êbok¹ sieæ neuronow¹ " << std::endl;
    std::cout << "model sieci bazuje na prceptronie wielowarstwowym " << std::endl;
    std::cout << "puki co rozpoznaje odrecznie napisane cyfry od 0-9 " << std::endl;
    std::cout << "obs³ugjece dane : " << std::endl;
    std::cout << "- zbior odrêcznie napisanych liczb MNIST (pliki binarne)" << std::endl;
    std::cout << "- obraz w pliku binarnym 28x28" << std::endl;
    std::cout << "- plik CSV (odpowiednio sformu³owane)" << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << "naciœnij enter aby przejsc dalej"; _getch();
    std::system("cls");


}

void menu::selectNet(NetParameters* par)
{
    std::system("cls");
    drow_heder();
    std::cout << "Wybierz numer Modelu sieci neuronowej : " << std::endl;
    std::cout << "1. Perceptron wielowarstwowy " << std::endl;
    std::cout << "Twoj wybor: ";
    int x = 0;
    std::cin >> x;
    switch (x) {
    case 1: par->set_select_Network("Perceptron wielowarstwowy");

    }
    std::system("cls");

    drow_heder();
    std::cout << "podaj kolejne warstwy sieci i iloœæ neuronów w warstwie w formacie '100,32,153' " << std::endl;
    std::cout << "podaj warstwy : " << std::endl;
    std::string s; 
    std::cin >> s;
    std::vector<int> vec;
    // Podziel ci¹g na tokeny oddzielone przecinkami
    std::string token;
    std::stringstream ss(s);
    while (std::getline(ss, token, ',')) 
    {
        vec.push_back(std::stoi(token));
    }
    par->set_params_layers(vec);
    std::system("cls");


    drow_heder();
    std::cout << "podaj podaj  min d³ugoœ wekrora b³êdu typ double :" << std::endl;
    std::cout << " podaj:  ";
    std::string str;
    std::cin >> str;
    size_t i;
    double d;
    d = std::stod(str);
    par->set_larningRation(d);
    std::system("cls");


    drow_heder();
    std::cout << "podaj podaj  iloœæ epok" << std::endl;
    std::cout << " podaj:  ";
    int e=0;
    std::cin >> e;
    par->set_numEpochs(e);
    std::system("cls");


}

void menu::selectData(NetParameters* par)
{
    std::system("cls");
    drow_heder();
    std::cout << "Wybierz typ danych do naki oraz testowania sieci neuronowej" << std::endl;
    std::cout << "1. zbior MNIST " << std::endl;
    std::cout << "2. plik .CSV "<<std::endl;
    std::cout << "3. pliki .json" << std::endl;
    std::cout << "Twoj wybor: ";
    int x = 0;
    std::cin >> x;
    switch (x) {
    case 1: par->set_select_data("MNIST"); break;
    case 2: par->set_select_data("CSV"); break;
    case 3: par->set_select_data("json"); break;

    }
    std::system("cls");

    if (x == 1)
    {
        drow_heder();
        std::cout << "podaj œcie¿kê dostêpu do doanych " << std::endl;
        std::cout << "sciezka: ";
        std::string path;
        std::string pathLabel;
        std::cin >> path; 
        std::cout << "sciezka do pliku label: ";
        std::cin >> pathLabel;
        par->set_path_data(path);
        par->set_pathLabel(pathLabel);
        std::system("cls");

    }
}

void menu::select_learned_Net(NetParameters* par)
{
    std::system("cls");
    drow_heder();
    std::cout <<  "chcesz douczyæ istniej¹ sieæ neuronowa ?" << std::endl;
    std::cout << "1. tak " << std::endl;
    std::cout << "2. nie " << std::endl;
    std::cout << "Twoj wybor: ";
    int x = 0;
    std::cin >> x;
    std::system("cls");

    if (x == 1)
    {
        drow_heder();
        std::cout << "podaj œcie¿kê dostêpu do pliku:  " << std::endl;
        std::cout << "sciezka: ";
        std::string path;
        std::cin >> path;
        par->set_path_netModel(path);
        std::system("cls");

    }

}

void menu::one_img(NetParameters* par)
{
    std::system("cls");
    drow_heder();
    std::cout << "podaj œcie¿kê dostêpu do zdj:  " << std::endl;
    std::cout << "sciezka: ";
    std::string path;
    std::cin >> path;
    par->set_path_data(path);
    std::system("cls");

}



void menu::start_menu(NetParameters* parameters)
{
    
    std::cout << "=========================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "MENU" << std::endl;
    std::cout << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "wybierz dostêpn¹ opcje :" << std::endl;
    std::cout << "1. do³¹czenie danych ucz¹cych  " << std::endl;
    std::cout << "2. wybranie istniej¹cego modelu " << std::endl;
    std::cout << "3. sprawdzenie jednego zdj w bliku bin 28x28 " << std::endl;
    std::cout << "4. wybranie parametrów sieci neuronowej " << std::endl;
    std::cout << "5. START UCZENIE SIECI NEURONOWEJ " << std::endl;
    std::cout << "6. spr jednego zdj " << std::endl;
    std::cout << "7. spr jednego zdj " << std::endl;
    std::cout << "Twoj wybor: ";
    int x = 0;
    std::cin >> x;
    switch (x)
    {
        case 1:
        {
            selectData(parameters);
            break;

        }
        case 2:
        {
            select_learned_Net(parameters);
            break;
        }
        case 3:
        {
            
            break;
        }
        case 4:
        {
            selectNet(parameters);
            break;
        }
        case 5:
        {
            startNetwork(parameters);
            _getch();
            break;
        }
        case 6:
        {
            
            break;
        }
        case 7:
        {
            exit(1);
            break;
        }
    }
    std::system("cls");

}

int menu::main_loop()
{
    NetParameters* parameters = new NetParameters();
    heloInformaction();
    while (1)
    {
        start_menu(parameters);

    }
    return 0;
}

void menu::drow_heder()
{
    std::cout << "=========================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Wybieranie parametrow sieci neuronowej " << std::endl;
    std::cout << std::endl;
    std::cout << "=========================================================================" << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
}

void startNetwork(NetParameters* par)
{
    Data_hendler* d;
    MNIST_data_handler m;
    CSV_data_handler c;
    d = &m;
    d->read_feature_vector(par->get_path_data().c_str());
    d->read_feature_labels(par->get_pathLabel().c_str());
    d->make_nomalized_data();
    d->split_data();
    d->count_classes();

    NeuronNetwork* net = new NeuronNetwork(
        par->get_params_layers(),
        d->get_trening_data()->at(0)->get_nomalized_feature_vector()->size(),
        d->get_num_class(),
        par->get_larningRation());

    net->set_trening_data(d->get_trening_data());
    net->set_test_data(d->get_test_data());
    net->set_validaction_data(d->get_validaction_data());
    net->train(par->get_numEpochs());
    net->validate();
    std::cout << net->test()<<std::endl;

}
