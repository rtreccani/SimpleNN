#include <math.h>
#include "helpers.h"


float randFloat(){
    return(static_cast <float> (rand()) / static_cast <float> (RAND_MAX) - 0.5);
}


void intToUnary(int val/*to be converted*/, float* result/*of width 10*/){
    float result[10];
    for(int i = 0; i < 9; i++){
        if(i == val){
            result[i] = 1.0;
        }
        else{
            result[i] = 0.0;
        }
    }
    return;
}