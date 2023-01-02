#include "Neuron.h"

double generateRandomDouble(double lowerBound, double upperBound)
{
    std::random_device rd;  // Use a random device to seed the generator
    std::mt19937 gen(rd());  // Use the Mersenne Twister as the generator
    std::uniform_real_distribution<> dis(lowerBound, upperBound);  // Define the range

    return dis(gen);
}

Neuron::Neuron(int prev_layer_size, int current_layer_size)
{
	init_Weights(prev_layer_size);

}

void Neuron::init_Weights(int prev_layer_size)
{
	std::default_random_engine gen;
	std::normal_distribution<double> distbu(0.0, 1.0);
    for (int i = 0 ; i < prev_layer_size; i++)
    {
        weights.push_back(generateRandomDouble(-1.0, 1.0));
    }

}
