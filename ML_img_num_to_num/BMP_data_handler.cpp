#include "BMP_data_handler.h"

void BMP_data_handler::read_feature_vector(const std::string& path)
{
    const int BMP_HEADER_SIZE = 54;
    std::ifstream bmpFile(path, std::ios::binary);
    if (!bmpFile)
    {
        std::cerr << "Nie uda³o siê otworzyæ pliku " << path << '\n';
        exit(1);
    }

    // Odczytaj nag³ówek pliku BMP.
    char header[BMP_HEADER_SIZE];
    bmpFile.read(header, BMP_HEADER_SIZE);

    // Odczytaj szerokoœæ i wysokoœæ obrazu.
    int width = *reinterpret_cast<int*>(&header[18]);
    int height = *reinterpret_cast<int*>(&header[22]);

    // Odczytaj wartoœci pixeli i zapisz je do wektora.
    std::vector<uint8_t> pixels(width * height * 3);
    bmpFile.read(reinterpret_cast<char*>(pixels.data()), pixels.size());


}
