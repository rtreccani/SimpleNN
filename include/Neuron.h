#ifndef NEURON_H
#define NEURON_H
#include <vector>

#define ALPHA 0.01

using namespace std;

class Neuron{
    public: 
        Neuron();
        virtual float computeOutput() = 0;
        virtual void backPropogate(float expected) = 0;
        virtual void backPropogate(float expected, float weight) = 0;
        int _index;
        int _layer;
};

class InputNeuron: public Neuron{
    public:
        InputNeuron(int layer, int index);
        InputNeuron(int layer, int index, int _value);
        float computeOutput() override;
        void changeValue(float val);
        void backPropogate(float expected) override;
        void backPropogate(float expected, float weight) override;
    private:
        float _value;
};

class HiddenNeuron: public Neuron{
    public:
        HiddenNeuron(){};
        HiddenNeuron(int layer, int index);
        float computeOutput() override;
        void backPropogate(float expected) override;
        void backPropogate(float expected, float weight) override;
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
    void backPropogate(float expected) override;
};  
#endif
