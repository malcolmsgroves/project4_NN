#include "NN.h"

using namespace std;

NN::NN(double learningRate, int numTrainInputs, int numTestInputs,
       int numOutputs, int mapSize, vector<vector<int> > trainInputs,
       vector<vector<int> > testInputs, vector<int> trainTargets,
       vector<int> testTargets, int maxEpochs):
  num_train_inputs(numTrainInputs), num_test_inputs(numTestInputs),
  num_outputs(numOutputs), map_size(mapSize),
  learning_rate(learningRate), train_inputs(trainInputs),
  test_inputs(testInputs), train_targets(trainTargets),
  test_targets(testTargets), max_epochs(maxEpochs) {

  srand(time(NULL));
  initialize_weights();
}

void NN::initialize_weights() {
  outputs.reserve(num_outputs);

  for(int i = 0; i < num_outputs; i++)
    for(int j = 0; j < map_size; j++)
      outputs[i].weights.push_back(2*rand()/RAND_MAX +1);
}

//void NN::test() {
//    cout << "in test" << endl;
//}
//
// void NN::train() {
//   cout << "in train" << endl;
//   for(int i = 0; i < max_epochs; i++) {
//     for(int input = 0; input < num_train_inputs; input++) {
//       double target = train_targets[input];
//       for(int output = 0; output <num_outputs; output++) {
// 	double dot_product = 0;
// 	for(int weight_index = 0; weight_index < map_size; weight_index++) {
// 	  dot_product += train_inputs[input][weight_index]*outputs[output].weights[weight_index];
// 	}
// 	double g = activation_function(dot_product);
// 	double g_prime = ddx_activation_function(dot_product);
// 	update_weights(output,g,g_prime,target);
//       }
//     }
//   }
// }

void update_weights(int output_index, double g, double g_prime, double target) {

}

double NN::activation_function(double x) {
  return 1/(1+exp(.5-x));
}

double NN::ddx_activation_function(double x) {
  return (1.64872*exp(x))/(1.64872*exp(x));
}
