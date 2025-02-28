#include "NeuronNetwork.h"
#include "Data_hendler.h"
#include "Layer.h"
#include <numeric>
#include <windows.h>
#include <gdiplus.h>



NeuronNetwork::NeuronNetwork(std::vector<int> spec, int inputSize, int numClasses, double learningRate)
{
    for (int i = 0; i < spec.size(); i++)
    {
        if (i == 0)
        {
            layers.push_back(new Layer(inputSize, spec.at(0))); // pierwsza warstwa neuron�w ilo�� wej�� neurona = ilo�ci danych wej�ciowych ilo�� neuron�w ilo�� okre�lonej w wektorze spec 
        }

        else
        {
            layers.push_back(new Layer(spec.at(i - 1), spec.at(i))); // kolejne werstwy neuron�w, ilo�� wej��neurona = spec ilo�� nuron�w =spec 
        }

    }
    layers.push_back(new Layer(layers.at(layers.size()-1)->neurons.size(), numClasses)); // ostatnie warstwwa neuron�w
    this->learningRate = learningRate;
}

NeuronNetwork::~NeuronNetwork() {}

double NeuronNetwork::activate(std::vector<double> weights, std::vector<double> input)
{
    double activation = weights.back(); // r�nica miedzy warto�ci� liczon� a prawdziw� 
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
                n->delta = errors.at(j) * this->transferDerivative(n->output); // gradnient jak zmieni� wagi
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
        std::cout << "Interation epoch's: " <<i<<"Error= "<<sumError << std::endl;

    }
}

double NeuronNetwork::test()
{
    /*for (Data* d : *test_data)
    {
        std::vector<double> outputs = fprop(d);
        double max= outputs.at(0);
        for (double m : outputs)
        {
            if (max < m) max = m;
        }
        if(max == )

    }*/

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

double NeuronNetwork::test2()
{
    double counter = 0;
    for(int m =0; m< test_data->size() ; m++)
    {
        Data* d = test_data->at(m);
        std::vector<double> outputs = fprop(d);
        double max = outputs.at(0);
        int index = 0;
        for (int i = 0 ; i<outputs.size(); i++)
        {
            if (max < outputs.at(i))
            {
                max = outputs.at(i);
                index = i;
            }
                
        }
        if (index == d->get_label())
        {
            counter += 1.0;
        }
        
        if (m < 50)
        {
            d->show_one_img();
            std::cout << " max " << max << std::endl;
            std::cout << " index " << index << std::endl;
           
            std::cout << std::endl;
            int u = 0;
            for (double d : outputs)
            {
                std::cout << u << " " << d << std::endl;
                u++;
            }
            double sumOutputs = 0;
            for (double s : outputs)
            {
                sumOutputs += s;

            }
            std::cout << " presition fit :  " << max / sumOutputs   << std::endl;
        }
        

    }
    std::cout << "countr :" << counter << std::endl;
    double performance_test = counter / test_data->size();
     return performance_test;
}

double NeuronNetwork::validate2()
{
    double counter = 0;
    for (int m = 0; m < test_data->size(); m++)
    {
        Data* d = test_data->at(m);
        std::vector<double> outputs = fprop(d);
        double max = outputs.at(0);
        int index = 0;
        for (int i = 0; i < outputs.size(); i++)
        {
            if (max < outputs.at(i))
            {
                max = outputs.at(i);
                index = i;
            }

        }
        if (index == d->get_label())
        {
            counter += 1.0;
        }


    }
    double performance_test = counter / test_data->size();
    return performance_test;
    return 0.0;
}

bool NeuronNetwork::fit_example(Data* img)
{

    // caltulate max output and index_enum for max

    std::vector<double> outputs = fprop(img); // calculate otuputs of network for Data

    double max = outputs.at(0);
    int index = 0;
    for (int i = 0; i < outputs.size(); i++)
    {
        if (max < outputs.at(i))
        {
            max = outputs.at(i);
            index = i;
        }

    }
    
    //show img
    img->show_one_img();

    std::cout  << std::endl;
    std::cout << " max  output: " << max << std::endl;
    std::cout << " fit index " << index << std::endl;
    
    // calculete tst precision and show weights 
    double sumOutputs = 0;
    for (double s : outputs)
    {
        sumOutputs += s;

    }
    std::cout << " sure  " << max/ sumOutputs << std::endl;

    std::cout << std::endl;
    int u = 0;
    for (double d : outputs)
    {
        std::cout << "output: nr." << u << " = " << std::fixed << d << "\t\t sure = " << d / sumOutputs * 100 << "%" << std::endl;
        u++;
    }

    // cheek fit num == label and show
    bool validatiofit = false;
    if (index == img->get_label())
    {
        std::cout << "validation fit : true  " << std::endl;
        bool validatiofit = true;
    }
    else
    {
  
         std::cout << "validation fit : false  " << std::endl;
         bool validatiofit = false;
    
    }

    
    return validatiofit;

}


