#ifndef HELPERS_H
#define HELPERS_H

#include "Neuron.h"

using namespace std;

float randFloat();

void intToUnary(int, float*);

float MSE(float* a, float* b, int listSize);

void createInputLayer(int size, vector<InputNeuron>* thisLayer);

//for when you're attaching to an input layer
void createHiddenLayer(int size, vector<InputNeuron>& prevLayer, vector<HiddenNeuron>* thisLayer);

void createOutputLayer(int size, vector<HiddenNeuron>& prevLayer, vector<OutputNeuron>* thisLayer);

#endif