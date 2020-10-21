#include <stdio.h>
#include <math.h>
#include <vector>


using namespace std;

#include "Neuron.h"
#include "fileio.h"
#include "helpers.h"

#define L0SIZE 28*28
#define L1SIZE 40
#define L2SIZE 10


int main(){
    
    vector<InputNeuron> inputLayer;
    createInputLayer(L0SIZE, &inputLayer);

    vector<HiddenNeuron> hiddenLayerOne;
    createHiddenLayer(L1SIZE, inputLayer, &hiddenLayerOne);
   

    vector<OutputNeuron> outputLayer;
    createOutputLayer(L2SIZE, hiddenLayerOne, &outputLayer);
    

    
    for(int i = 0; i < 60000; i++){
        int label = getNewTrainingDataAndLabel(i, inputLayer);
        //printf("label is %d\n", label);
        float target[10];
        intToUnary(label, target);

        float actual[10];

        for(int loops=0; loops < 1; loops++){
            for(int ne = 0; ne < outputLayer.size(); ne++){
                actual[ne] = outputLayer[ne].computeOutput();
                outputLayer[ne].backPropogate(target[ne]);
            }
        //printf("error for sample %d is %f   \n", label, MSE(target, actual, 10));
        }
        

        
        //printf("error for sample %d is %f   ", label, MSE(target, actual, 10));
        if(i % 100 == 0){
            drawPlot(actual, label);
        }
    }
    

    return(0); 


    
}