#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function declarations
string cleanString(string &string1);
void anagramCheck(string string1, string string2);

int main()
{
	string string1, string2;

	//Get strings from user
	getline(cin, string1); 
	getline(cin, string2);

	// Cleans string for anagram check
	cleanString(string1);
	cleanString(string2);
	
	//Completes anagram check and prints verdict
	anagramCheck(string1, string2);
	
	return 0;
}


// Precondition: Takes in a string passed by reference to physically change the string for later use. Called in anagramCheck.
// Post Condition: Returns a cleaned string stripped of non-alphabetical characters and all letters are lower cased
string cleanString(string &string1)
{
	string new_string = ""; // New string is created to store clean characters
	for (int i = 0; i < string1.length(); i++){
		if (isalpha(string1[i])) 
			new_string += tolower(string1[i]); // Appends all alphabetical characters lower cased
	}
	string1 = new_string;
	return string1;
}

// Precondition: Takes in two strings that you want to compare (calls cleanString automatically)
// Post Condition: Prints whether the strings are anagrams or not
void anagramCheck(string string1, string string2)
{
	// Calls clean string for the user
	cleanString(string1);
	cleanString(string2);

	// Automatically decides strings aren't anagrams if lengths are different post clean
	if (string1.length() != string2.length()) {
        	cout << "The strings are not anagrams" << endl;
		return;
    	}
	
	// used_index array of zeros to track when a letter index was already matched 
	const int size = string1.length();
    	int used_index[size];
    
	for (int i = 0; i < size; i++) 
  		used_index[i] = 0;


 	for (int i = 0; i < size; i++) {
		bool foundMatch = false;
        
		for (int j = 0; j < size; j++) {
			// Match is found if string 1 and 2 have the same letter and an match wasn't already made in same index
			if ((string1[i] == string2[j]) && (used_index[j] == 0)) {
				used_index[j] = 1;
                		foundMatch = true;
                		break;
            		}
        	}
        
	// If any letter is off, foundMatch is false
        if (!foundMatch) {
		cout << "The strings are not anagrams" << endl;
		return;
	}
    }

    cout << "The strings are anagrams" << endl;
}
