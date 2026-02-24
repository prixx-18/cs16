#include <iostream> // for cout, cin, endl
#include <string>   // for string
using namespace std;
#include "pheaders.h"

int main() {
    	// Get sentence from user and store it in inputString using getline (accounting for whitespaces)
    	string inputString;
	cout << "Enter sentence:" << endl;
	getline(cin, inputString);

	// Clean up the string using cleanUp
    	cleanUp(inputString);
	
	// Check if string is palindrome using isPalindrome and print appropriate message
	if (isPalindrome(inputString))
		cout << "It is a palindrome." << endl;
	else
		cout << "It is not a palindrome." << endl;

    	return 0;
}
