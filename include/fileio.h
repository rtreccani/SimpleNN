#ifndef FILEIO_H
#define FILEIO_H
#include "Neuron.h"

int getNextPixel();

int getNextLabel();

int getNewTrainingDataAndLabel(int index, vector<InputNeuron>& inputNeurons);


#endif