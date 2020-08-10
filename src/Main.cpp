#include <stdio.h>
#include <math.h>
#include <vector>
#include <unistd.h>

using namespace std;

#include "Neuron.h"
#include "fileio.h"
#include "helpers.h"

#define L0SIZE 28*28
#define L1SIZE 40
#define L2SIZE 10


int main(){
    printf("ok %d, %d, %d, %d\n", sizeof(Neuron), sizeof(InputNeuron), sizeof(HiddenNeuron), sizeof(OutputNeuron));
    int labelVal = getNextLabel();
    
    vector<InputNeuron> inputLayer;
    createInputLayer(L0SIZE, &inputLayer);

    vector<HiddenNeuron> hiddenLayerOne;
    createHiddenLayer(L1SIZE, inputLayer, &hiddenLayerOne);
   

    vector<OutputNeuron> outputLayer;
    createOutputLayer(L2SIZE, hiddenLayerOne, &outputLayer);
    
    printf("added all neurons\n");
    //do the recursive backwards sweep through the NN to find the outputs
    for(int i = 0; i < outputLayer.size(); i++){
        printf("output %d, value %f\n", i, outputLayer[i].computeOutput());
    }

    return(0); 


    
}