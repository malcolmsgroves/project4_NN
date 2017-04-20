#include "NN.h"

using namespace std;

NN::NN(double learningRate, int numTrainInputs, int numTestInputs,
       int numOutputs, int mapSize, int **trainInputs,
       int **testInputs, int *trainTargets, int *testTargets,
       int maxEpochs) :
  num_train_inputs(numTrainInputs), num_test_inputs(numTestInputs),
  num_outputs(numOutputs), map_size(mapSize),
  learning_rate(learningRate), train_inputs(trainInputs),
  test_inputs(testInputs), train_targets(trainTargets),
  test_targets(testTargets), max_epochs(maxEpochs) {
  this->outputs = new output[map_size];
}


//void NN::test() {
//    cout << "in test" << endl;
//}
//
//void NN::train() {
//    cout << "in train" << endl;
//}


// don't forget to delete all mallocs!
