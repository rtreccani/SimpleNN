#include <math.h>
#include "helpers.h"
#include "fileio.h"
#include "Neuron.h"

using namespace std;

float randFloat(){
    return(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) - 0.5);
}

//both lists must be of order given by listSize
float MSE(float* listA, float* listB, int listSize){
    float squareError = 0.0;
    for(int i = 0; i < listSize; i++){
        squareError += pow((listA[i] - listB[i]), 2);
    }
    return(squareError/listSize);
}

void intToUnary(int val, float* arr){
    for(int i = 0; i < 10; i++){
        if(i == val){
            arr[i] = 1.0;
        }
        else{
            arr[i] = 0.0;
        }
    }
}


//wow vectors so cool B)
void createInputLayer(int size, vector<InputNeuron>* thisLayer){
    
    for(int i = 0; i < size; i++){
        thisLayer->push_back(InputNeuron(0, i));//, getNextPixel()));
    }
}

void createHiddenLayer(int size, vector<InputNeuron>& prevLayer, vector<HiddenNeuron>* thisLayer){
    for(int i = 0; i < size; i++){
        HiddenNeuron h(1, i);
        h.setBias(randFloat());
        for (int j = 0; j < prevLayer.size(); j++){
            h.addSynapse(&prevLayer[j], randFloat());
        }
        thisLayer->push_back(h);
    }
}

void createOutputLayer(int size, vector<HiddenNeuron>& prevLayer, vector<OutputNeuron>* thisLayer){
    for(int i = 0; i < size; i++){
        OutputNeuron h(2, i);
        h.setBias(randFloat());
        for (int j = 0; j < prevLayer.size(); j++){
            h.addSynapse(&prevLayer[j], randFloat());
        }
        thisLayer->push_back(h);
    }
}