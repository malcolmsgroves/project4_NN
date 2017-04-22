#include "main.h"

using namespace std;

int main(int argc, char** argv) {
    
    string trainFile  = argv[1];
    string testFile = argv[2];
    double learningRate = stod(argv[3]);
    int outputNodes = stoi(argv[4]);
    
    
    
    int max_epochs = 50;
    
    Problem digit_prob = read_file("optdigits.tra");
    cout << digit_prob.map_size << endl;
    cout << digit_prob.num_inputs << " " << digit_prob.inputs.size() << endl;
    for(int i = 0; i < digit_prob.num_inputs; ++i) {
        //cout << digit_prob.inputs[10][i] << ", ";
    }
    //cout << digit_prob.targets[10];
    cout << "hey " << endl;
    cout << digit_prob.inputs[0].size() << endl;
    NN net(learningRate,digit_prob.num_inputs,digit_prob.num_inputs,outputNodes,digit_prob.map_size, digit_prob.inputs,digit_prob.inputs,digit_prob.targets,digit_prob.targets,max_epochs);
    net.train();
    net.test();
}


// reads in sets of digit recognition problems from files
Problem read_file(string problem_file_name) {
    
    Problem digit_recognition;
    digit_recognition.map_size = 0;
    digit_recognition.num_inputs = 0;
    vector<int> dummy_inputs;
    digit_recognition.inputs.push_back(dummy_inputs);
    
    string curr_number = "";
    char curr_char;
    
    ifstream problem_stream;
    problem_stream.open(problem_file_name.c_str(), ios::in);
    
    if(!problem_stream.good()) {
        cout << "Error: not able to open file" << endl;
    }
    
    // read the first line and determine map size
    while(problem_stream.peek() != '\n') {
        problem_stream.get(curr_char);
        
        // if comma, save number and move on
        if(curr_char == ',') {
            digit_recognition.inputs[digit_recognition.num_inputs].push_back(stoi(curr_number));
            curr_number.clear();
            ++digit_recognition.map_size;
        }
        
        // else, add char to curr number string
        else {
            curr_number += curr_char;
        }
    }
    
    while(problem_stream.peek() != EOF) {
        
        problem_stream.get(curr_char);
        
        // if comma, save number and move on
        if(curr_char == ',') {
            digit_recognition.inputs[digit_recognition.num_inputs].push_back(stoi(curr_number));
            curr_number.clear();
        }
        
        // if new line, cap off current digit image and move on to next one
        else if(curr_char == '\n') {
            digit_recognition.targets.push_back(stoi(curr_number));
            curr_number.clear();
            ++digit_recognition.num_inputs;
            //cout << digit_recognition.num_inputs << endl;
            digit_recognition.inputs.push_back(dummy_inputs);
        }
        
        // else, add char to curr number string
        else {
            curr_number += curr_char;
        }
    }
    return digit_recognition;  
}
