#include "Big_data.h"


using namespace std;

const int IMAGE_WIDTH = 28;
const int IMAGE_HEIGHT = 28;
const int IMAGE_SIZE = IMAGE_WIDTH * IMAGE_HEIGHT;



void Big_data::readMNISTImages(const string& fileName)
{
    ifstream file(fileName, ios::binary);

    if (!file.is_open())
    {
        cerr << "Failed to open file: " << fileName << endl;
        exit(1);
    }

    int magicNumber = 0;
    int numberOfImages = 0;
    int imageWidth = 0;
    int imageHeight = 0;

    file.read((char*)&magicNumber, sizeof(magicNumber));
    magicNumber = ((magicNumber & 0xff) << 24) | ((magicNumber & 0xff00) << 8) | ((magicNumber & 0xff0000) >> 8) | ((magicNumber & 0xff000000) >> 24);

    file.read((char*)&numberOfImages, sizeof(numberOfImages));
    numberOfImages = ((numberOfImages & 0xff) << 24) | ((numberOfImages & 0xff00) << 8) | ((numberOfImages & 0xff0000) >> 8) | ((numberOfImages & 0xff000000) >> 24);

    file.read((char*)&imageWidth, sizeof(imageWidth));
    imageWidth = ((imageWidth & 0xff) << 24) | ((imageWidth & 0xff00) << 8) | ((imageWidth & 0xff0000) >> 8) | ((imageWidth & 0xff000000) >> 24);

    file.read((char*)&imageHeight, sizeof(imageHeight));
    imageHeight = ((imageHeight & 0xff) << 24) | ((imageHeight & 0xff00) << 8) | ((imageHeight & 0xff0000) >> 8) | ((imageHeight & 0xff000000) >> 24);

    if (magicNumber != 0x803)
    {
        cerr << "Invalid magic number: " << magicNumber << endl;
        exit(1);
    }

    if (imageWidth != IMAGE_WIDTH || imageHeight != IMAGE_HEIGHT)
    {
        cerr << "Invalid image size: " << imageWidth << "x" << imageHeight << endl;
        exit(1);
    }

    

    for (int i = 0; i < numberOfImages; i++)
    {
        MNISTImage image;
        unsigned char pixel = 0;
        for (int j = 0; j < IMAGE_SIZE; j++)
        {
           
            file.read((char*)&pixel, sizeof(pixel));
            image.data.push_back((int)pixel);
            
        }
        
        vector_images.push_back(image);
    }

   
}

void Big_data::show()
{
    int x28 = 0;
    for (int i = 0; i < 100; i++)
    {
        for(int r=0;r<28;r++)
        {
            for (int c = 0; c < 28; c++)
            {
                std::cout << vector_images.at(i).data.at(c + r*28)<< "\.";
                
            }
            cout << endl;
            
        }
        cout << endl;
        cout << endl;
        cout << endl;
    }

}
