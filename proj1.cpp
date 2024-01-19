#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <sstream>
#include <cstdlib>
#include "proj1.h"

using namespace std;

/*Stores vectors that include index permeatations which will be used
  to find all the ways in which the values can be ordered
*/
vector<vector<int>> perms;
//false = arithetic operations, true = bitwise operations
bool operation;
//the number to evaluate to
int eval;
//the list of 5 values
int values[5];
//count of valid matches
int count = 0;

void start(bool o, int e, int v[5]) { //26 lines
    //set global variables
    operation = o;
    eval = e;
    for (int i = 0 ; i < 5 ; i++) {
        values[i] = v[i];
    }
    //find permatations
    char a[] = "ABCDE";
    permute(a,0,4);
    //perform operations
    for (unsigned int i = 0 ; i < perms.size() ; i++) {
        int temp[5];
        for (unsigned int j = 0 ; j < perms[i].size() ; j++) {
            temp[j] = values[perms[i][j]];
        }
        combine(temp);
    }
    //generate output
    string outputOperation;
    if (operation) {
        outputOperation = " bitwise";
    } else {
        outputOperation = " arithmetic";
    }

    cout << count << outputOperation << " expressions found that evaluate to " << eval << endl;

}

void combine(int list[]) { //14 lines
    for (int a = 0 ; a < 5; a++) {
        for (int b = 0 ; b < 5; b++) {
            for (int c = 0 ; c < 5; c++) {
                for (int d = 0 ; d < 5; d++) {
                    if (calculate(list,a,b,c,d) == eval) { //valid operation
                        output (list,a,b,c,d);
                        count ++;
                    }
                }
            }
        }
    }
}

int calculate (int list[], int a,int b,int c,int d) { //8 lines
    //decoding for-loop index values as indecies
    int result;
    result = operate(a,list[0],list[1]);
    result = operate(b,result,list[2]);
    result = operate(c,result,list[3]);
    result = operate(d,result,list[4]);
    return result;
}

void output (int list[],int a,int b,int c, int d) { //7 lines
    //creating parenthesis
    string out = "(" + to_string(list[0]) + convertOutput(a) + to_string(list[1]) + ")";
    out = "(" + out + convertOutput(b) + to_string(list[2]) + ")";
    out = "(" + out + convertOutput(c) + to_string(list[3]) + ")";
    out = out + convertOutput(d) + to_string(list[4]);
    cout << out << endl;
}

string convertOutput(int o) { //27 lines
    if (!operation) { //arithetic
        if (o == 0) {
            return "+";
        } else if( o == 1) {
            return "-";
        } else if( o == 2) {
            return "*";
        } else if( o == 3) {
            return "/";
        } else if( o == 4) {
            return "%";
        }
    } else { //bitwise
        if (o == 0) {
            return "<<";
        } else if( o == 1) {
            return ">>";
        } else if( o == 2) {
            return "&";
        } else if( o == 3) {
            return "|";
        } else if( o == 4) {
            return "^";
        }
    }
    return "Error";
}

int operate(int o, int x, int y) { //27 lines
    if (!operation) { //arithmetic
        if (o == 0) {
            return x + y;
        } else if( o == 1) {
            return x - y;
        } else if( o == 2) {
            return x * y;
        } else if( o == 3) {
            return x / y;
        } else if( o == 4) {
            return x % y;
        }
    } else { //bitwise
        if (o == 0) {
            return x << y;
        } else if( o == 1) {
            return x >> y;
        } else if( o == 2) {
            return x & y;
        } else if( o == 3) {
            return x | y;
        } else if( o == 4) {
            return x ^ y;
        }
    }
    return -1;
}

void permute(char a[], int l, int r) { //20 lines
    // Base case
    if (l == r) {
        vector<int> temp;
        for (int i = 0 ; i <= r ; i++) {
            //must be between 0-4
            int asci = (int) a[i] - 65;
            temp.push_back(asci);
        }
        perms.push_back(temp);
    } else {
        // Permutations made
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);
            // recursive call
            permute(a, l+1, r);
            //backtrack
            swap(a[l], a[i]);
        }
    }
}
