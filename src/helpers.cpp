#include <math.h>
#include "helpers.h"
#include "fileio.h"
#include "Neuron.h"
#include <unistd.h>
#include "gnuplot-iostream.h"

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

void drawPlot(float* values, int label){
    //static Gnuplot gp(">script.gp");
    static Gnuplot gp;
    gp << "clear\n";
    char* title = (char*)malloc(400*sizeof(char));
    sprintf(title, "set xrange[0:9]\nset title '%d'\nset yrange [-0.1:1.1]\nfilter(x,min,max) = (x > min && x < max) ? x : 1/0\nset table 'data-smoothed'\nplot '-' using 1:2 smooth csplines\n", label) ;
    gp << title;
    vector<pair<double, double>> data;
    for(int i = 0; i < 10; i++){
        data.emplace_back(double(i), double(values[i]));
    }
    gp.send1d(data);
    sprintf(title, "unset table\nplot 'data-smoothed' using (filter($1, %f, %f)):2 with filledcurves x1 lt 1 notitle,\\\n''  using 1:2 with lines lw 2 lt 1\n", (float(label)-0.5), (float(label)+0.5));
    gp << title;
}