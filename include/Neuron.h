#ifndef NEURON_H
#define NEURON_H
#include <vector>

using namespace std;

class Neuron{
    public: 
        Neuron();
        virtual float computeOutput() = 0;
        int _index;
        int _layer;
};

class InputNeuron: public Neuron{
    public:
        InputNeuron(int layer, int index, int _value);
        float computeOutput() override;
    private:
        float _value;
};

class HiddenNeuron: public Neuron{
    public:
        HiddenNeuron(){};
        HiddenNeuron(int layer, int index);
        float computeOutput() override;
        void addSynapse(Neuron* previousNeuron, float weight);

        void setBias(float b);
        float getBias(void);

        float getWeight(int index);
        void setWeight(int index, float w);

    protected:
        vector<float> weights;
        float bias = 0.0;
        int previousNeuronCount = 0;
        vector<Neuron*> previousNeurons;
};

class OutputNeuron: public HiddenNeuron{
    public:
        OutputNeuron(int layer, int index);
};  
#endif
