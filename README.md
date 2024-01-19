# Target Value Expression Finder
Calculates expressions using either arithmetic or bitwise operations to achieve a specific target value. 

## Description
ExpressionEvaluator is a versatile tool designed to generate expressions that evaluate to a specified target value using either arithmetic or bitwise operations. This project parses command line arguments to determine the operation mode, target value, and a list of numbers. It then computes all possible expressions that achieve the target value using the specified operation mode.

## Features
- **Two Modes of Operation:** Choose between arithmetic and bitwise operations.
- **Customizable Input:** Specify a target value and a set of numbers to be used in expressions.
- **Permutation and Combination Logic:** Generates all permutations of the given numbers and evaluates all possible expressions.
- **Command Line Interface:** Easy-to-use command line interface for inputting parameters.

## How to Use
**Compile the Code:** \
Ensure you have a C++ compiler installed. Compile the code using your compiler. For example, with g++:
```bash
g++ -o ExpressionEvaluator main.cpp
```
**Run the Program:** \
Use the following command line arguments to run the program:

**-b:** Use bitwise operations. \
**-a:** Use arithmetic operations. \
**-e [number]:** Specify the target value to evaluate to. \
**-v [number1 number2 number3 number4 number5]:** Specify a list of five values to use in expressions. 

## Example:
```bash
./ExpressionEvaluator -a -e 100 -v 1 2 3 4 5
```
This example will use arithmetic operations to find expressions with the numbers 1, 2, 3, 4, and 5 that evaluate to 100.

## Code Breakdown
**Command Line Parsing (in main function):** The main function parses command line arguments to set the mode of operation (arithmetic or bitwise), the target evaluation number (eval), and a list of values (values). The command-line flags used are -b for bitwise operation mode, -a for arithmetic operation mode, -e followed by a number for the evaluation target, and -v followed by five numbers for the values list.

**Initialization and Permutation (in start function):** This function initializes the global variables and generates all permutations of the indices (0 to 4, representing the values array) using the permute function. Each permutation is stored in the global perms vector.

**Combination and Calculation (in combine and calculate functions):** For each permutation of values, combine tries every combination of operations (encoded by loop indices) to find expressions that evaluate to the target number. The calculate function computes the result of an expression based on the provided operation indices and values.

**Operation Execution (in operate function):** This function performs the actual arithmetic or bitwise operation based on the operation mode and the operands.

**Output (in output and convertOutput functions):** These functions handle the formatting and output of the expressions that evaluate to the target number. convertOutput translates operation indices into corresponding operation symbols (like +, <<, etc.).

**Permutation Generation (in permute function):** This function recursively generates permutations of the array a (which initially contains characters 'A' to 'E') and converts these to indices (0 to 4) for storing in perms.

## Requirements
C++ Compiler (e.g., g++, clang++) \
Standard C++ libraries
