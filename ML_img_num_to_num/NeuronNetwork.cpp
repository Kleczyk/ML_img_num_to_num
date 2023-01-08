#include "NeuronNetwork.h"
#include "Data_hendler.h"
#include "Layer.h"
#include <numeric>

NeuronNetwork::NeuronNetwork(std::vector<int> spec, int inputSize, int numClasses, double learningRate)
{
    for (int i = 0; i < spec.size(); i++)
    {
        if (i == 0)
        {
            layers.push_back(new Layer(inputSize, spec.at(0))); // pierwsza warstwa neuronów iloœæ wejœæ neurona = iloœci danych wejœciowych iloœæ neuronów iloœæ okreœlonej w wektorze spec 
        }

        else
        {
            layers.push_back(new Layer(spec.at(i - 1), spec.at(i))); // kolejne werstwy neuronów, iloœæ wejœæneurona = spec iloœæ nuronów =spec 
        }

    }
    layers.push_back(new Layer(layers.at(layers.size()-1)->neurons.size(), numClasses)); // ostatnie warstwwa neuronów
    this->learningRate = learningRate;
}

NeuronNetwork::~NeuronNetwork() {}

double NeuronNetwork::activate(std::vector<double> weights, std::vector<double> input)
{
    double activation = weights.back(); // ró¿nica miedzy wartoœci¹ liczon¹ a prawdziw¹ 
    for (int i = 0; i < weights.size()-1; i++)
    {
        activation += weights.at(i) * input.at(i);
    }
    return activation; 

  
}


double NeuronNetwork::transfer(double activation)
{
    return 1.0 / (1.0 + exp(-activation));
}


double NeuronNetwork::transferDerivative(double output)     //f'(x) = f(x)(1-f(x)) // pochodna z funckji signamoidalnej 
{
    return output = output * (1 - output);
}

std::vector<double> NeuronNetwork::fprop(Data* data)
{
    std::vector<double> inputs = *data->get_nomalized_feature_vector();
    for (int i = 0; i < layers.size(); i++)
    {
        Layer* layer = layers.at(i);
        std::vector<double> new_inputs;
        for (Neuron* n : layer->neurons)
        {
            double activation = activate(n->weights, inputs);
            n->output = this->transfer(activation);
            new_inputs.push_back(n->output);
        }
        inputs = new_inputs;
    }
    return inputs; //inputs next layer 

}

void NeuronNetwork::bprop(Data* data)
{
    for (int i = layers.size() - 1; i >= 0; i--)
    {
        Layer* layer = layers.at(i);
        std::vector<double> errors;
        if (i != layers.size() - 1)
        {
            for (int j = 0; j < layer->neurons.size(); j++)
            {
                double error = 0.0;
                for (Neuron* n : layers.at(i + 1)->neurons) //nest layer
                {
                    error += (n->weights.at(j) * n->delta); // caltulate error for one neuron 
                }
                errors.push_back(error);
            }

        }
        else
        {
            for (int j = 0; j < layer->neurons.size(); j++)
            {
                Neuron* n = layer->neurons.at(j);
                errors.push_back((double)data->get_class_vector()->at(j) - n->output);
            }
            for (int j = 0; j < layer->neurons.size(); j++)
            {
                Neuron* n = layer->neurons.at(j);
                n->delta = errors.at(j) * this->transferDerivative(n->output); // gradnient jak zmieniæ wagi
            }
        }
    }
}

void NeuronNetwork::updateWeights(Data* data)
{
    std::vector<double> inputs = *data->get_nomalized_feature_vector();
    for(int i= 0; i< layers.size(); i++)
    {
        if (i != 0)
        {
            for (Neuron* n : layers.at(i - 1)->neurons)
            {
                inputs.push_back(n->output);
            }
            for (Neuron* n : layers.at(i)->neurons)
            {
                for (int j = 0; j < inputs.size(); j++)
                {
                    n->weights.at(j) += learningRate * n->delta * inputs.at(j);
                    
                }
                n->weights.back() += learningRate * n->delta;
            }
            
        }
        inputs.clear();

    }
}

int NeuronNetwork::predict(Data* data)
{
    std::vector<double> outputs = fprop(data);
    return std::distance(outputs.begin(), std::max_element(outputs.begin(), outputs.end()));

}



void NeuronNetwork::train(int numEpochs)
{
    for (int i = 0; i < numEpochs; i++)
    {
        double sumError = 0.0;

        
        for (int m = 0; m < trening_data->size(); m++)   
        {
            Data* data = trening_data->at(m);
            std::vector<double> outputs = fprop(data);
            std::vector<int> *expected = data->get_class_vector();
            double tempErrorSum = 0.0;
            for (int j = 0; j < outputs.size(); j++)
            {
                tempErrorSum += pow((double)expected->at(j) - outputs.at(j), 2);

            }
            sumError += tempErrorSum;
            bprop(data);
            updateWeights(data);
        }
        std::cout << "Epoka nr. " <<i<< "\t suma pope³nianych b³êdów na nuronach= "<<sumError << std::endl;

    }
}

double NeuronNetwork::test()
{
    double numCorrect = 0.0;
    double count = 0.0;
    
    for (Data* data : *test_data)
    {
        count++;
        int index = predict(data);

        if (data->get_class_vector()->at(index) == 1)
        {
            numCorrect++;
        }
    }
    testPerformance = (numCorrect / count);
    return testPerformance;

}

double NeuronNetwork::validate()
{
    double numCorrect = 0.0;
    double count = 0.0;

   
    for (int m = 0; m < validaction_data->size(); m++)
    {
        Data* data = trening_data->at(m);

        count++;
        int index = predict(data);
        if (data->get_class_vector()->at(index) == 1)
        {
            numCorrect++;
        }
    }
    double validPerformance = (numCorrect / count);
    return validPerformance;
}
void NeuronNetwork::showNetParms()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "parametry sieci :" << std::endl;
    std::cout << "iloœæ warst ukrytych " << layers.size() - 1 << std::endl;
    for (int i = 0; i < layers.size() - 1; i++)
    {
        std::cout << "iloœæ neuronuw w warstwie nr." << i << " " << layers.at(i)->neurons.size() << std::endl;
    }
    
}
//{
//    double numCorrect = 0.0;
//    double count = 0.0;
//    for (Data* data : *this->validaction_data)
//    {
//        count++;
//        int index = predict(data);
//        if (data->get_class_vector().at(index) == 1) numCorrect++;
//    }
//    printf("Validation Performance: %.4f\n", numCorrect / count);
//}


