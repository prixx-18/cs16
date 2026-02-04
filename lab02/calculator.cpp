// Calculator.cpp
// By: Priyansh Nath
// Created on: Jan 15th

#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]){
	
	// Check for valid amount of command line arguments
	if (argc != 4){
		cerr << "Numbers of arguments is incorrect." << endl;
		exit(1);
	}
	
	// Convert cstrings to usable ints and chars
	int number1 = atoi(argv[1]);
	int number2 = atoi(argv[3]);
	char operation = argv[2][0];
	
	// Check for operation type and perform operation
	switch(operation){
		case '+':
			cout << number1 + number2;
			break;
		case '-':
                        cout << number1 - number2;
			break;
		case 'x':
                        cout << number1 * number2;
			break;
		case '%':
			if (number2 == 0){
				cerr << "Cannot divide by zero." << endl;
				exit(1);
			}  
			cout << number1 % number2;
			break;
		// Default behaviour is to exit
		default:
			cerr << "Bad operation choice." << endl;
			exit(1);
			break;
	}

	cout << endl;

	return 0;
}
