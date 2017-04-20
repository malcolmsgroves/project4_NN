#include "NN.h"

using namespace std;

NN::NN(double learningRate, int numTrainInputs, int numTestInputs,
       int numOutputs, int mapSize, vector<vector<int>> trainInputs,
       vector<vector<int>> testInputs, vector<vector<int>> trainTargets,
       vector<vector<int>> testTargets, int maxEpochs):
  num_train_inputs(numTrainInputs), num_test_inputs(numTestInputs),
  num_outputs(numOutputs), map_size(mapSize),
  learning_rate(learningRate), train_inputs(trainInputs),
  test_inputs(testInputs), train_targets(trainTargets),
  test_targets(testTargets), max_epochs(maxEpochs) {

  outputs.reserve(numOutputs);
}


//void NN::test() {
//    cout << "in test" << endl;
//}
//
//void NN::train() {
//    cout << "in train" << endl;
//}
