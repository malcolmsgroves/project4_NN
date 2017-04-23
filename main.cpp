#include "main.h"

using namespace std;

int main(int argc, char** argv) {
    
    string trainFile  = argv[1];
    string testFile = argv[2];
    double learningRate = stod(argv[3]);
    int outputNodes = stoi(argv[4]);
    



    
    Problem digit_prob = read_file("optdigits-32x32.tra");
    cout << "Map Size" << digit_prob.map_size << endl;
    cout << "Number of training inputs" << digit_prob.num_inputs << " " << digit_prob.inputs.size() << endl;
    //cout << digit_prob.targets[10];
    NN net(learningRate,digit_prob.num_inputs,digit_prob.num_inputs,outputNodes,digit_prob.map_size, digit_prob.inputs,digit_prob.inputs,digit_prob.targets,digit_prob.targets,50);
    net.train();
    net.test();

    return 0;
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
  if(problem_stream.peek() == 'B') {
    for(int i = 0; i < 3; i++){
      problem_stream.ignore(999999999,'\n');
    } 
    int inputs_index = 0;
    while(problem_stream.peek() != EOF) {
      for(int i = 0; i < 32; i++) {
	for(int j = 0; j < 32; j++) {
	  problem_stream.get(curr_char);
	  curr_number =  curr_char;
	  digit_recognition.inputs[inputs_index].push_back(stoi(curr_number));
	}
	problem_stream.get(curr_char); // get rid of \n char
      }
      // get rid of ' ' and set target
      problem_stream.get(curr_char);
      problem_stream.get(curr_char);
      curr_number = curr_char;
      digit_recognition.targets.push_back(stoi(curr_number));
      problem_stream.get(curr_char);
      inputs_index++;
      vector <int> dummy_vector;
      digit_recognition.inputs.push_back(dummy_vector);
    }
  
    digit_recognition.map_size = 32*32;
    digit_recognition.num_inputs = inputs_index;
    return digit_recognition;
  

  } else {
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
}
