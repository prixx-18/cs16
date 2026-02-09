#include <iostream> // for cin, cout, endl
#include <cstdlib>  // for exit()
#include <cmath>    // for pow() function ONLY

// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 2 functions below.
int bin2d(string binstring);
string dec2bh(string sdec, char bh);
void flipString(string &string);

int main ( int argc, char *argv[] ) 
{
	// Checks for correct amount of commad line arguments
	if (argc != 3)
	{
		cerr << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
		exit(1);
	}
	
	// Checks to see if correct conversion command is inputted
	string option = string(argv[1]);

	if (option != "d2b" && option != "d2h" && option != "b2d")
	{
		cerr << "Usage: converter <options: d2b, d2h, b2d> <value>" << endl;
		exit(1);
	}
	
	// Converts command line argumens to usable C++ strings
	string converter = argv[1];
	string value = argv[2];

	// Calls appropriate function based on conversion command
	if (converter == "d2b")
		cout << "The value in binary is: " << dec2bh(value, 'b') << endl;	
	else if (converter == "d2h")
		cout << "The value in hexadecimal is: " << dec2bh(value, 'h') << endl;
	else
	{	
		int result = bin2d(value);
		if (result == -1) 
		{
			cerr << "Binary value contains non-binary digits." << endl;
        		exit(1);
    		}

    		cout << "The value in decimal is: " << result << endl;
	}

	return 0;
}

// Pre-condition: Takes in a string passed by reference so it can be directly changed
// Post-Condition: Flips the order of the string
void flipString(string &inputString)
{
	string flippedString = inputString;
	int len = inputString.length();
	for (int i = len - 1; i >= 0; i--)
		flippedString[len - 1 - i] = inputString[i];

	inputString = flippedString;
}

// Pre-condition: Takes in a binary code of type string
// Post-condition: Returns the binary code converted to base 10 decimal form of type int
int bin2d(string binstring)
{
	// Initialize a sum and flip the binary string so LSB is at index 0
	int sum = 0;
	flipString(binstring);
		
	// Implements the positional strategy, raising every increasing position to i
	for (int i = 0; i < binstring.length(); i++)
	{
		// returns -1 if binary code includes invalid numbers
		if (binstring[i] != '0' && binstring[i] != '1')
			return -1;	
		
		// Only adds to sum if the corresponding string is 1
		if (binstring[i] == '1')
                    sum += pow(2, i);
	}
	return sum;
}

// Pre-condition: Takes a base 10 number as type string and a character 'b' or 'h' indicating which base to convert to
// Post-condition: Returns the base 10 number converted to either 'b' binary or 'h' hex as type string
string dec2bh(string sdec, char bh)
{
	// Use ASCII codes to convert string into int
	int quotient = 0;
    	for(int i = 0; i < sdec.length(); i++) 
        	quotient = quotient * 10 + (sdec[i] - '0');

	// Returns 0 if the entered decimal number was 0
	if (quotient == 0) 
		return "0";

	string converted = "";
	string hexDigits = "0123456789ABCDEF"; // String of hex characters in appropriate index

	// Converts to hex if char argument was 'h'
	if (bh == 'h')
	{
		// Implements division algorithm for base 16
		while (quotient != 0)
		{
			converted += hexDigits[quotient % 16];
			quotient /= 16;
		}

		// String is flipped to move LSB to the right
		flipString(converted);
		return converted;	
	}
	
	// Converts to binary if char argument was 'b'
	else if (bh == 'b')
	{
		// Implements division algorithm for base 2
		while (quotient != 0)
		{
			converted += (quotient % 2) + '0'; // Use ASCII code to convert ints into concatanable strings
			quotient /= 2;
		}

		// String is flipped to move LSB to the right
		flipString(converted);
		return converted;
	}
}
