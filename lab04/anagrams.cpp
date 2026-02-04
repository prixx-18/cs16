#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// MISSING FUNCTION DECLARATIONS HERE (you can remove these comments)
string cleanString(string &string1);
void anagramCheck(string string1, string string2);

int main()
{
    // MISSING CODE HERE (you can remove these comments)
	// Get strings from user -- USE:   getline(cin, <string_variable>);
	// Clean strings
	// Check to see if they are anagrams
	// Report if they are or not anagrams
	string string1, string2;

	getline(cin, string1);
	getline(cin, string2);

	cleanString(string1);
	cleanString(string2);
	
	anagramCheck(string1, string2);
	
	return 0;
}


// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
string cleanString(string &string1)
{
	string new_string = "";
	for (int i = 0; i < string1.length(); i++){
		if (isalpha(string1[i]))
			new_string += tolower(string1[i]);
	}
	string1 = new_string;
	return string1;
}

void anagramCheck(string string1, string string2)
{
	cleanString(string1);
	cleanString(string2);

	if (string1.length() != string2.length()) {
        	cout << "The strings are not anagrams" << endl;
		return;
    	}
	
	const int size = string1.length();
    	int used_index[size];
    
	for (int i = 0; i < size; i++) 
  		used_index[i] = 0;


 	for (int i = 0; i < size; i++) {
		bool foundMatch = false;
        
		for (int j = 0; j < size; j++) {
			if ((string1[i] == string2[j]) && (used_index[j] == 0)) {
				used_index[j] = 1;
                		foundMatch = true;
                		break;
            		}
        	}
        
        if (!foundMatch) {
		cout << "The strings are not anagrams" << endl;
		return;
	}
    }

    cout << "The strings are anagrams" << endl;
}
