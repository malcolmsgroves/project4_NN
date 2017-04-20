#include "main.h"

using namespace std;

int main(int argc, char** argv) {
    
//    string trainFile  = argv[1];
//    string testFile = argv[2];
//    double learningRate = stod(argv[3]);
//    int outputNodes = stoi(argv[4]);
//    
//    NN net(learningRate, outputNodes);
//    net.train();
//    net.test();
    
    Problem digit_prob = read_file("optdigits.tra");
    cout << digit_prob.map_size << endl;
    cout << digit_prob.num_inputs << endl;
    for(int i = 0; i < digit_prob.map_size; ++i) {
        cout << digit_prob.inputs[10][i] << ", ";
    }
    cout << digit_prob.targets[10];
}

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
    
    while(problem_stream.peek() != '\n') {

        problem_stream.get(curr_char);
        if(curr_char == ',') {
            digit_recognition.inputs[digit_recognition.num_inputs].push_back(stoi(curr_number));
            curr_number.clear();
            ++digit_recognition.map_size;
        }
        else {
            curr_number += curr_char;
        }
    }
    
//    digit_recognition.targets.push_back(stoi(curr_number));
//    curr_number.clear();
//    ++digit_recognition.num_inputs;
//    digit_recognition.inputs.push_back(dummy_inputs);
    
    while(problem_stream.peek() != EOF) {
        //cout << curr_char << endl;
        
        problem_stream.get(curr_char);

        if(curr_char == ',') {
            digit_recognition.inputs[digit_recognition.num_inputs].push_back(stoi(curr_number));
            //cout << curr_number << "\t";
            curr_number.clear();
        }
        else if(curr_char == '\n') {
            //cout << curr_number << endl;
            digit_recognition.targets.push_back(stoi(curr_number));
            curr_number.clear();
            ++digit_recognition.num_inputs;
            cout << digit_recognition.num_inputs << endl;
            digit_recognition.inputs.push_back(dummy_inputs);
        }
        else {
            curr_number += curr_char;
        }
    }
    
    
    return digit_recognition;
}















