#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <cstdlib>
#include "proj1.h"

using namespace std;

/*
  Function: Parses command line arguments and passes
  them into the main alorithm.
  Inputs: argc - length of cmd ln args
  char*argv[] - list of command line arguments
  Outputs: int - exit status
*/

int main(int argc, char*argv[]) { //21 lines
    bool operation; //bitwise or arithetic
    int eval; //number to evaluate to
    int values[5]; //list of values
    for (int i = 1 ; i < argc ; i++) {
        string current = argv[i];
        if (current == "-b") {
            operation = true;
        } else if (current == "-a") {
            operation = false;
        } else if (current == "-e") {
            current = argv[i+1];
            eval = stoi(current);
        } else if (current == "-v") {
            for (int j = 0 ; j < 5 ; j++) {
                current = argv[i + 1 + j];
                values[j] = stoi(current);
            }
        }
    }
    //launch algorithm
    start(operation,eval,values);
}
