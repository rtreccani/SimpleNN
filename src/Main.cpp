#include <stdio.h>
#include <math.h>
#include <vector>
#include <unistd.h>

using namespace std;

#include "Neuron.h"
#include "fileio.h"
#include "helpers.h"



int main(){
    int labelVal = getNextLabel();
    
    vector<InputNeuron> inputLayer;
    for(int i = 0; i < 28*28; i++){
        inputLayer.push_back(InputNeuron(0,i, getNextPixel()));
    }

    vector<HiddenNeuron> hiddenLayerOne;
    for(int i = 0; i < 100; i++){
        HiddenNeuron h(1, i);
        h.setBias(randFloat());
        for (int j = 0; j < inputLayer.size(); j++){
            h.addSynapse(&inputLayer[j], randFloat());
        }
        hiddenLayerOne.push_back(h);
    }

    vector<OutputNeuron> outputLayer;
    for(int i = 0; i < 10; i++){
        OutputNeuron o(2, i);
        o.setBias(randFloat());
        for(int j = 0; j < hiddenLayerOne.size(); j++){
            o.addSynapse(&hiddenLayerOne[j], randFloat());
        }
        outputLayer.push_back(o);
    }

    printf("added all neurons\n");

    //do the recursive backwards sweep through the NN to find the outputs
    for(int i = 0; i < outputLayer.size(); i++){
        printf("output %d, value %f\n", i, outputLayer[i].computeOutput());
    }

    return(0);


    
}