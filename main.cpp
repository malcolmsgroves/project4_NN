#include "main.h"

using namespace std;

int main(int argc, char** argv) {
    
    string trainFile  = argv[1];
    string testFile = argv[2];
    double learningRate = stod(argv[3]);
    int outputNodes = stoi(argv[4]);
    
    srand(time(NULL));
    
    int max_epochs = 50;
    
    Problem trainProb = read_file(trainFile);
    Problem testProb = read_file(testFile);
    
    string run_command;
    cout << "Run all the tests? (y/n)" << endl;
    cin >> run_command;
    
    if(run_command == "n") {
        NN net(learningRate, trainProb, testProb, outputNodes,max_epochs);
        cout << "made it" << endl;
        vector<double> results = net.train();
        cout << "again" << endl;
        cout << "Percent correct: " << results.back() << endl;
    }
    
<<<<<<< HEAD
    else {
        string nn_filename;
        ofstream output_file;
        cout << "name output file (with .csv): " << endl;
        cin >> nn_filename;
        
        string output_string = "Neural Networks\nlearning rate,map_size,output_nodes,epoch,correct_tests\n";
        
        int max_epochs = 50;
        
        vector<double> lr_vector {0.01, 0.1, 0.5, 1.0};
        // set map size
        for(int i = 0; i < 2; ++i) {
            string train_file, test_file;
            
            if(i == 0) {
                train_file = "optdigits-8x8-int.tra";
                test_file = "optdigits-8x8-int.tes";
            }
            else {
                train_file = "optdigits-32x32.tra";
                test_file = "optdigits-32x32.tes";
            }
            
            for(int j = 0; j < 2; ++j) {
                
                int output_nodes;
                if(j == 0) output_nodes = 1;
                else output_nodes = 10;
                
                for(int lr = 0; lr < 4; ++lr) {
                    
                    double learning_rate = lr_vector[lr];
                    Problem train_prob = read_file(train_file);
                    Problem test_prob = read_file(test_file);
                    
                    
                    NN net(learningRate, train_prob, test_prob, outputNodes,max_epochs);
                    
                    vector<double> results = net.train();
                    
                    for(int epoch = 0; epoch < results.size(); ++ epoch) {
                        output_string += to_string(learning_rate) + "," + to_string(train_prob.map_size) + "," + to_string(output_nodes) + "," + to_string(epoch) + "," + to_string(results[epoch]) + "\n";
                    }
                    
                    
                    
                    
                    
                }
            }
        }
        
        output_file.open(nn_filename);
        output_file << output_string;
        output_file.close();
    }
    
=======
    Problem digit_prob = read_file("optdigits-32x32.tra");
    cout << "Map Size" << digit_prob.map_size << endl;
    cout << "Number of training inputs" << digit_prob.num_inputs << " " << digit_prob.inputs.size() << endl;
    //cout << digit_prob.targets[10];
    NN net(learningRate,digit_prob.num_inputs,digit_prob.num_inputs,outputNodes,digit_prob.map_size, digit_prob.inputs,digit_prob.inputs,digit_prob.targets,digit_prob.targets,50);
    net.train();
    net.test();

    return 0;
>>>>>>> afe51d70171a1d315ff18207c4b6d0676cd4e19a
}


// reads in sets of digit recognition problems from files
Problem read_file(string problem_file_name) {
    
<<<<<<< HEAD
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
=======
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
>>>>>>> afe51d70171a1d315ff18207c4b6d0676cd4e19a
}
