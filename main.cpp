#include "main.h"

using namespace std;

int main(int argc, char** argv) {
  string trainFile  = argv[1];
  string testFile = argv[2];
  double learningRate = stod(argv[3]);
  int outputNodes = stoi(argv[4]);

  NN net(learningRate, outputNodes);
  net.train();
  net.test();
}
