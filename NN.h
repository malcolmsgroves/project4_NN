#ifndef __NN_h
#define __NN_h

#include <vector>

using namespace std;

struct output {
    double *weights;
};


class NN {
public:
    NN(double learningRate, int numTrainInputs, int numTestInputs, int numOutputs, int mapSize, int **trainInputs, int **testInputs, int *trainTargets, int *testTargets, int maxEpochs);
    void test();
    void train();

private:
    int num_train_inputs;
    int num_test_inputs;
    int num_outputs;
    int map_size;

    double learning_rate;
    int **train_inputs;
    int **test_inputs;
    int *train_targets;
    int *test_targets;
    output *outputs;
    int max_epochs;

};

#endif
