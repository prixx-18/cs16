/* Skeleton file for vertical.cpp
 * For use in CS16
 * (c) 2024 by Z.Matni
 */
// Do not add any other #include statement!
#include <iostream>
using namespace std;

// Declare printV() here
void printV(unsigned long int num);

int main() {
    	// 1. Get user input
    	long int num;
    	cout << "Enter integer: ";
    	cin >> num;
    	// 2. Check input and pass it on to printV()
	if (num < 0)
    		cout << "Input must be a positive integer." << endl;
	else
		printV(num);

	return 0;
}

// Define printV() here
void printV(unsigned long int num)
{
	// Base case: print single digit number and new line
	if (num <= 9)
		cout << num << endl;
	// Recursive case: Recursively call printV with truncated quotient
	else {
		printV(num / 10); // Recursive call pauses parent function to run its own work
		cout << (num % 10) << endl; // Every value is printed when recursive calls hit base case and unwind
	}
}
