#include"Layer.h" 

Layer::Layer(int prev_layer_size, int current_layer_size)
{
	currentLayerSize = current_layer_size;
	for (int i = 0; i < current_layer_size; i++)
	{
		Neuron* N = new Neuron(prev_layer_size , current_layer_size);
		neurons.push_back(N);

	}
}