#include "Neuron.h"
#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

float sigmoid(float x){
    return(1.0/(1.0+exp(-x)));
}

//constructors
Neuron::Neuron(){
}

//overrides base(Neuron) constructor for the InputNeuron class
HiddenNeuron::HiddenNeuron(int layer, int index){
    _index = index;
    _layer = layer;
    previousNeuronCount = 0;
}

//overrides base(Neuron) constructor for the HiddenNeuron class
InputNeuron::InputNeuron(int layer, int index, int value){
    _index = index;
    _layer = layer;
    _value = value/255.0;
}

//overrides base(Neuron) constructor for the OutputNeuron class
OutputNeuron::OutputNeuron(int layer, int index){
    _index = index;
    _layer = layer;
    previousNeuronCount = 0;
}

//pure computeOutput function
float Neuron::computeOutput(){
    printf("Mega fucking warning, this is the virtual function, needs to be overloaded\n");
    return(0.0);
}

//overrides the computeOutput of the base Neuron class
float InputNeuron::computeOutput(){
    return(_value);
}

//overrides the computeOutput of the base Neuron class
float HiddenNeuron::computeOutput(){
    float sum = bias;
    //printf("evaluating %d, %d\n", _layer, _index);
    for(int i = 1; i < weights.size(); i++){
        sum  += weights[i]*(previousNeurons[i]->computeOutput());
    }
    return(sigmoid(sum));
}

void HiddenNeuron::addSynapse(Neuron* previousNeuron, float weight){
    previousNeurons.push_back(previousNeuron);
    weights.push_back(weight);
    previousNeuronCount++;
}

void HiddenNeuron::setBias(float b){
    bias = b;
}