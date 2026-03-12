// file: functions.cpp for newanagrams

// Define all member functions for class AString
//    as well as all other functions that need definition

// Default Constructor
AString::AString() {
    StringValue = "";
}

// Parameterized Constructor
AString::AString(string inputString) {
    StringValue = inputString;
}

string AString::getStringValue() {return StringValue;}

// Precondition: Takes in a string passed by reference to physically change the string for later use. Called in anagramCheck.
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

void AString::countLetters(int arr[])
{
	for (int i = 0; i < StringValue.size(); i++)
	{
		char currentLetter = StringValue[i];
		
		int index = currentLetter - 'a';

		arr[index]++;
	}
}

void AString::getAString() {getline(cin, StringValue);}

bool compareCounts(int ca1[], int ca2[])
{
	for (int i = 0; i < 26; i++)
	{
		if (ca1[i] != ca2[i])
			return false;
	}

	return true;
}

