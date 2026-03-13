// Default Constructor
AString::AString() {
    StringValue = "";
}

// Parameterized Constructor
AString::AString(string inputString) {
    StringValue = inputString;
}

// Accessor
string AString::getStringValue() {return StringValue;}

// Pre-condition: Takes in a string passed by reference to physically change the string for later use. Called in anagramCheck.
// Post Condition: Returns a cleaned string stripped of non-alphabetical characters and all letters are lower cased
void AString::cleanUp()
{
	string new_string = ""; // New string is created to store clean characters
	for (int i = 0; i < StringValue.length(); i++){
                if (isalpha(StringValue[i]))
                        new_string += tolower(StringValue[i]); // Appends all alphabetical characters lower cased
        }
        StringValue = new_string;
}

// Pre-condition: Takes in an integer array of 26 elements (representing each lower case letter of the alphabet) all initialized to 0
// Post-condition: Changes the array to represent how many times a letter was seen in an object's string variable
void AString::countLetters(int arr[])
{
	for (int i = 0; i < StringValue.size(); i++)
	{
		char currentLetter = StringValue[i];
		int index = currentLetter - 'a'; // Computes difference in char ASCII values for precise index matching (ex: 'a' - 'a' = 0, and 'a' is indeed meant to be index 0)
		arr[index]++; // Increments appropriate index
	}
}

// Pre-conditon: None
// Post-condition: Class public member function to get a string from the user
void AString::getAString() {getline(cin, StringValue);}

// Pre-condition: Pass in 2 int arrays of size 26
// Post-condition: Returns whether the 2 arrays are identical
bool compareCounts(int ca1[], int ca2[])
{
	for (int i = 0; i < 26; i++)
	{
		if (ca1[i] != ca2[i])
			return false; // Immediately returns false if any mismatch is found
	}

	return true;
}

