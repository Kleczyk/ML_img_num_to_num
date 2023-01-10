#include "Data.h"
#include "Data_hendler.h"
#include "CSV_data_handler.h"
#include "MNIST_data_handler.h"
#include "Neuron.h"
#include "NeuronNetwork.h"
#include "NetParameters.h"
#include <locale.h>
#include "menu.h"
#include <cstdint>


const int BMP_HEADER_SIZE = 54;
void readBmpHeader(const std::string& fileName)
{
    std::ifstream bmpFile(fileName, std::ios::binary);
    if (!bmpFile)
    {
        std::cerr << "Nie uda³o siê otworzyæ pliku " << fileName << '\n';
        exit(1);
    }

    // Odczytaj nag³ówek pliku BMP.
    char header[BMP_HEADER_SIZE];
    bmpFile.read(header, BMP_HEADER_SIZE);

    // Odczytaj pola nag³ówka pliku BMP.
    uint32_t fileSize = *reinterpret_cast<uint32_t*>(&header[2]);
    int32_t width = *reinterpret_cast<int32_t*>(&header[18]);
    int32_t height = *reinterpret_cast<int32_t*>(&header[22]);
    uint16_t bitsPerPixel = *reinterpret_cast<uint16_t*>(&header[28]);
    uint32_t compressionMethod = *reinterpret_cast<uint32_t*>(&header[30]);
    uint32_t imageSize = *reinterpret_cast<uint32_t*>(&header[34]);

    // Wyœwietl odczytane pola nag³ówka pliku BMP.
    std::cout << "Wielkoœæ pliku: " << fileSize << '\n';
    std::cout << "Szerokoœæ obrazu: " << width << '\n';
    std::cout << "Wysokoœæ obrazu: " << height << '\n';
    std::cout << "Liczba bitów na piksel: " << bitsPerPixel << '\n';
    std::cout << "Metoda kompresji: " << compressionMethod << '\n';
    std::cout << "Wielkoœæ danych obrazu: " << imageSize << '\n';
}

std::vector<uint8_t> readBmpPixelsRLE(const std::string& fileName)
{
    std::ifstream bmpFile(fileName, std::ios::binary);
    if (!bmpFile)
    {
        std::cerr << "Nie uda³o siê otworzyæ pliku " << fileName << '\n';
        exit(1);
    }

    // Odczytaj nag³ówek pliku BMP.
    char header[BMP_HEADER_SIZE];
    bmpFile.read(header, BMP_HEADER_SIZE);

    // Odczytaj szerokoœæ i wysokoœæ obrazu.
    int width = *reinterpret_cast<int*>(&header[18]);
    int height = *reinterpret_cast<int*>(&header[22]);

    // Odczytaj wartoœci pixeli i zapisz je do wektora.
    std::vector<uint8_t> pixels(width * height);
    int pixelIndex = 0;

    while (pixelIndex < width * height)
    {
        // Odczytaj bajt kontrolny.
        uint8_t controlByte = bmpFile.get();

        // Jeœli bajt kontrolny jest mniejszy od 128, to oznacza to, ¿e nastêpuje ci¹g powtarzaj¹cych siê bajtów.
        if (controlByte < 128)
        {
            // Odczytaj nastêpny bajt, który jest wartoœci¹ pixela.
            uint8_t pixelValue = bmpFile.get();

            // Zapisz ci¹g powtarzaj¹cych siê bajtów do wektora.
            for (int i = 0; i < controlByte + 1; ++i)
            {
                pixels.push_back(pixelValue);
                pixelIndex++;
            }
        }
        // Jeœli bajt kontrolny jest równy lub wiêkszy od 128, to oznacza to, ¿e nastêpuje ci¹g ró¿nych bajtów.
        else
        {
            for (int i = 0; i < controlByte - 127; ++i)
            {
                pixels.push_back(bmpFile.get());
                pixelIndex++;
            }
        }
    }

    return pixels;
}

void displayImage(const std::vector<uint8_t>& pixels, int width, int height)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            std::cout << (pixels.at(y * width + x) == 0 ? ' ' : '#');
        }
        std::cout << '\n';
    }
}
int main()
{
    setlocale(LC_CTYPE, "Polish");

    //menu m1;
    //m1.main_loop();
        
  
    //QImage image("image.jpg");
    //std::ifstream bmpFile("D:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\BMP Image\\B5.bmp", std::ios::binary);
    //if (!bmpFile)
    //{
    //    std::cerr << "Nie uda³o siê otworzyæ pliku " << "dasd" << '\n';
    //    exit(1);
    //}

    //// Odczytaj nag³ówek pliku BMP.
    //char header[BMP_HEADER_SIZE];
    //char ilosc[4];
    //bmpFile.read(ilosc, 32);
    //char sze[2];
    //bmpFile.read(sze, 16);
    //char wy[2];
    //bmpFile.read(wy, 16);
    //char opis[2];
    //bmpFile.read(opis, 16);

    //Data_hendler* y;
    //MNIST_data_handler m;
    //y = &m;
    //std::cout << m.convert_to_little_endian((uint8_t)ilosc) <<std::endl;
    //std::cout << (int)sze << std::endl;
    //std::cout << (int)wy << std::endl;
    //std::cout << (int)opis << std::endl;
    //// Odczytaj wartoœci pixeli i zapisz je do wektora.
    //std::vector<uint8_t> pixels((int)wy * (int)sze * 3);
    //bmpFile.read(reinterpret_cast<char*>(pixels.data()), pixels.size());
    //
    //for (int i =0 ; i<pixels.size() ; i+=3)
    //{
    //    if (i % 28 == 0) std::cout << std::endl;
    //    int eq = (int)pixels.at(i) + (int)pixels.at(i + 1) + (int)pixels.at(i + 2);
    //    std::cout << eq << " ";
    //    
    //}
    

   
   /* std::vector<uint8_t> vec;
    vec = readBmpPixelsRLE("D:\\prz\\sem_3\\C++\\ML_proj\\ML_img_num_to_num\\BMP Image\\B5.bmp");

        
    for (int i = 0; i < vec.size(); i++)
    {
        if (i % 28 == 0)std::cout <<std:: endl; 
        std::cout << vec.at(i);
    }
 // */

	Data_hendler *d;
	MNIST_data_handler m;
	CSV_data_handler c;


	d = &m;
	d->read_feature_vector("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-images-idx3-ubyte.bin");
	d->read_feature_labels("d:\\prz\\sem_3\\c++\\ml_proj\\ml_img_num_to_num\\train-labels.idx1-ubyte");
    d->make_nomalized_data();
    d->split_data();
	d->count_classes();

    std::vector<int> hiddenLayers = { 1000, 500 ,100};
        NeuronNetwork* net = new NeuronNetwork(
            hiddenLayers,
            d->get_trening_data()->at(0)->get_nomalized_feature_vector()->size(),
            d->get_num_class(),
            0.4);
        net->set_trening_data(d->get_trening_data());
        net->set_test_data(d->get_test_data());
        net->set_validaction_data(d->get_validaction_data());


        net->train(7);
        const int choose_num = 500;
        std::cout << net->layers.at(0)->neurons.size() << std::endl;
        for (int i = 0; i < 10; i++)
        {



            d->get_trening_data()->at(choose_num+i)->show_one_img();   // pokaznie liczby 
            std::cout << "jest to liczba: ";
            std::cout << (int)d->get_trening_data()->at(choose_num + i)->get_label() << std::endl; // pokacznie jego labela 
            std::cout << std::endl;
            std::vector<double> outputs = net->fprop(d->get_test_data()->at(69));
            std::cout << " co dostajemy z funkcji fprop: " << std::endl;
            int u = 0;
            for (double d : outputs)
            {
                std::cout <<u<<" " << d << std::endl;
                u++;
            }
           /* std::cout << std::endl;
            for (int i = 0; i < net->layers.at(1)->neurons.size(); i++)
            {
                std::cout << net->layers.at(1)->neurons.at(i)->output << std::endl;
            }*/
        }

        

       /* for(int i = 0; i < net->layers.at(1)->neurons.size(); i++)
        {
            std::cout << net->layers.at(1)->neurons.at(i)->output << std::endl;
        }*/
        std::cout << "test2 performace" << net->test2() << std::endl;
        std::cout<<"validation performace" << net->validate() << std::endl;
        std::cout<<"test performance " << net->test() << std::endl;
 


}
