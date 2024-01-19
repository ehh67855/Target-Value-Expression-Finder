#ifndef proj1
#define proj1
#include <string>
#include <vector>

using namespace std;
/*
  Function: General encompassing method that is called in main method.
  Sets the values for global variables passed in through
  the command line arguments, generates permatations of values,
  finds all combinations of operators,
  and produces output.
  Inputs: bool o - false = arithmetic, true = bitwise operators
  int e - the number to evaluate to
  int v[5] - the array of values
  Outputs: Void
*/
void start (bool o,int e,int v[5]);

/*
  Function:Recursivly finds all permatations of numbers between 0-4
  and stores them in a 2D vector. These vectors will be used
  to find all the different ways the values can be rearranged
  Inputs: char a[] - a charecter sequence used in place of integers to allow for
  charecter arithmetic. These are then converted to ints.
  int l - the starting index
  int r - the ending index
  Outputs: void
  Assumptions: There will be only 5 values in the list
*/
void permute(char a[], int l, int r);

/*
  Function: Finds all combinations of operators that can be used.
  Inputs: int list[] - list of values
  Outputs: void
  Assumptions: There are only 5 values in the list
*/
void combine(int list[]);

/*
  Function: Converts for loop identifyers to operators,so that
  position of for-loops can be used to find all
  operation combinations.
  Inputs: int o - type of operation to perform
  int x - first value
  int y - second value
  Outputs: int - the result of the operation
*/
int operate(int o,int x,int y);

/*
  Function: Calls the combine method, integrating all values and operators
  to get a final number that an equation evaluates to.
  Inputs: int list - the list of values to reference
  int a - the first operator
  int b - the second operator
  int c - the third operator
  int d - the fourth operator
  Outputs: the result of the equation.
*/
int calculate (int list[], int a,int b,int c,int d);

/*
  Function: Adds parenthesis in the proper positions for the output.
  Inputs: int list - the list of values to reference
  int a - the first operator
  int b - the second operator
  int c - the third operator
  int d - the fourth operator
  Outputs: Void
*/
void output (int list[],int a,int b,int c, int d);

/*
  Function: Used to convert operations into strings so that they
  can be displayed in the output.
  Inputs: int list - the list of values to reference
  int a - the first operator
  int b - the second operator
  int c - the third operator
  int d - the fourth operator
  Outputs: the string version of an operator
*/
string convertOutput(int o);

#endif
