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
    for (int i = 0; i < weights.size(); i++)
    {
        activation += weights.at(i) * input.at(i);
    }
    return activation; 

    //double activation = weights.back(); // bias term
    //for (int i = 0; i < weights.size() - 1; i++)
    //{
    //    activation += weights[i] * input[i];
    //}
    //return activation;
}


//double NeuronNetwork::transfer(double activation)
//{
//    return 1.0 / (1.0 + exp(-activation));
//}
//
//double NeuronNetwork::transferDerivative(double output)
//{
//    return output * (1 - output);
//}
//
//std::vector<double> NeuronNetwork::fprop(Data* data)
//{
//    std::vector<double> inputs = *data->get_double_feature_vector();
//    for (int i = 0; i < layers.size(); i++)
//    {
//        Layer* layer = layers.at(i);
//        std::vector<double> newInputs;
//        for (Neuron* n : layer->neurons)
//        {
//            double activation = this->activate(n->weights, inputs);
//            n->output = this->transfer(activation);
//            newInputs.push_back(n->output);
//        }
//        inputs = newInputs;
//    }
//    return inputs; // output layer outputs
//}
//
//void NeuronNetwork::bprop(Data* data)
//{
//    for (int i = layers.size() - 1; i >= 0; i--)
//    {
//        Layer* layer = layers.at(i);
//        std::vector<double> errors;
//        if (i != layers.size() - 1)
//        {
//            for (int j = 0; j < layer->neurons.size(); j++)
//            {
//                double error = 0.0;
//                for (Neuron* n : layers.at(i + 1)->neurons)
//                {
//                    error += (n->weights.at(j) * n->delta);
//                }
//                errors.push_back(error);
//            }
//        }
//        else {
//            for (int j = 0; j < layer->neurons.size(); j++)
//            {
//                Neuron* n = layer->neurons.at(j);
//                errors.push_back((double)data->get_double_feature_vector().at(j) - n->output); // expected - actual
//            }
//        }
//        for (int j = 0; j < layer->neurons.size(); j++)
//        {
//            Neuron* n = layer->neurons.at(j);
//            n->delta = errors.at(j) * this->transferDerivative(n->output); //gradient / derivative part of back prop.
//        }
//    }
//}
//
//void NeuronNetwork::updateWeights(Data* data)
//{
//    std::vector<double> inputs = *data->getNormalizedFeatureVector();
//    for (int i = 0; i < layers.size(); i++)
//    {
//        if (i != 0)
//        {
//            for (Neuron* n : layers.at(i - 1)->neurons)
//            {
//                inputs.push_back(n->output);
//            }
//        }
//        for (Neuron* n : layers.at(i)->neurons)
//        {
//            for (int j = 0; j < inputs.size(); j++)
//            {
//                n->weights.at(j) += this->learningRate * n->delta * inputs.at(j);
//            }
//            n->weights.back() += this->learningRate * n->delta;
//        }
//        inputs.clear();
//    }
//}
//
//int NeuronNetwork::predict(Data* data)
//{
//    std::vector<double> outputs = fprop(data);
//    return std::distance(outputs.begin(), std::max_element(outputs.begin(), outputs.end()));
//}
//
//void NeuronNetwork::train(int numEpochs)
//{
//    for (int i = 0; i < numEpochs; i++)
//    {
//        double sumError = 0.0;
//        for (Data* data : *this->trening_data)
//        {
//            std::vector<double> outputs = fprop(data);
//            std::vector<int> expected = data->get_class_vector();
//            double tempErrorSum = 0.0;
//            for (int j = 0; j < outputs.size(); j++)
//            {
//                tempErrorSum += pow((double)expected.at(j) - outputs.at(j), 2);
//            }
//            sumError += tempErrorSum;
//            bprop(data);
//            updateWeights(data);
//        }
//        printf("Iteration: %d \t Error=%.4f\n", i, sumError);
//    }
//}
//
//double NeuronNetwork::test()
//{
//    double numCorrect = 0.0;
//    double count = 0.0;
//    for (Data* data : *this->trening_data)
//    {
//        count++;
//        int index = predict(data);
//        if (data->get_class_vector().at(index) == 1) numCorrect++;
//    }
//
//    testPerformance = (numCorrect / count);
//    return testPerformance;
//}
//
//void NeuronNetwork::validate()
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


