#ifndef __NN_h
#define __NN_h

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>
#include <cmath>

using namespace std;


class NN {
 public:
 NN(double learningRate, int outputNodes) :
  learning_rate(learningRate),
    output_nodes(outputNodes) {}

  void test();
  void train();

 private:
  double learning_rate;
  int output_nodes;

};

#endif
