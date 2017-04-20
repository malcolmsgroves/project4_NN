#ifndef __main_h
#define __main_h

#include "NN.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <sstream>

using namespace std;


struct Problem {
    
    vector<vector<int>> inputs;
    vector<int> targets;
    int num_inputs;
    int map_size;
    
};

Problem read_file(string problem_file_name);

#endif


