#include <iostream> // for cin, cout
#include <vector>   // for vector
#include <string>   // for getline()
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER LIBRARY!!! (zero grade penalty)
using namespace std;

// FUNCTION DECLARATION: YOU MUST DEFINE AND USE THIS (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use function split() below.
vector<string> split(string target, string delimiter);
void printVector(vector<string> stringVector);

int main() {

    // Initialize string variables
    	string target;
	string delimiter;

    // Get target string from user, get delimiter string from user
	cout << "Enter string to split:" << endl;
	getline(cin, target); 
	cout << "Enter delimiter string:" << endl;
	getline(cin, delimiter);

    // Call function split()
    	vector<string> splitString = split(target, delimiter);
    
    // Print results
	cout << "The substrings are: ";
    	printVector(splitString);
	cout << endl;

    return 0;
}

// Precondition: Takes two string arguments, the main target string and the string you want to split the target by
// Postcondition: Returns a vector of substrings that are split by the desired delimiter
vector<string> split(string target, string delimiter)
{
	vector<string> substrings;
	bool substringExists = false;

	// Exits the function if target or delimiter strings are empty
	if (target.size() == 0)
	{
        	cout << "No substrings." << endl;
        	exit(1);
    	}

	// If every element in target equals delimiter then no substrings exist	
	for (unsigned int i = 0; i < target.size(); i++)
	{
		if (target[i] != delimiter[0])
			substringExists = true;
	}

	if (!substringExists)
	{
		cout << "No substrings." << endl;
		exit(1);
	}

    	// String variable constructed for every substring between delimiters
    	string substring = "";
    	for (unsigned int i = 0; i < target.size(); i++)
    	{
        	// Cuts off substring if delimiter is detected
        	if (target[i] == delimiter[0])
        	{
	    		// Only pushes the substring if the substring isn't empty
            		if (substring != "")
            		{
                		substrings.push_back(substring);
                		substring = "";
            		}
        	}
        	else
            		// Concatonates character if it isn't delimiter
	    		substring += target[i];
    	}


    	// Pushes last substring if it isn't empty
    	if (substring != "")
        	substrings.push_back(substring);

    	return substrings;
}

// Takes in a vector of strings
// Prints the vector with each string encapsulated in "" and separated by commas
void printVector(vector<string> stringVector)
{
	for (unsigned int i = 0; i < stringVector.size(); i++)
	{
		// Omits comma from last substring printed
		if (i == stringVector.size() - 1)
		{
			cout << "\"" << stringVector[i] << "\"";
			return;
		}
	cout << "\"" << stringVector[i] << "\", ";
	}
}
