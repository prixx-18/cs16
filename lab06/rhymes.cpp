#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      iYou can declare/define other functions if you like as well,
//      but you must use the 3 functions below.
// See lab description for more on these functions.

void flipString(string &inputString);
string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() 
{
	// Instantiate ifstream object
	ifstream rhyme_stream;
	string file_name;
	
	// Get filename from user and attempt file open
	cout << "Enter filename: ";
	cin >> file_name;
	rhyme_stream.open(file_name);

	// Exit if file cannot open
	if (rhyme_stream.fail())
	{
		cerr << "Cannot open " << file_name << endl;
		exit(1);
	}

	int file_length = 0;

	// Get file length using getline's boolean output
	string temp;
	while (getline(rhyme_stream, temp))
    		file_length++;
	
	// Close and reopen file to reset to top
	rhyme_stream.close();
	rhyme_stream.open(file_name);

	// Create dynamic array
	string *last_words = new string[file_length];
	
	// Append each line's last word to array
	for (unsigned int i = 0; i < file_length; i++)
	{
		string poem_line;
		getline(rhyme_stream, poem_line);
		string last_word = findLastWord(poem_line);
		last_words[i] = last_word;
	}

	// Increment rhyme counter every time a rhyme is detected
	int rhyme_counter = 0;
	for (int i = 0; i < file_length - 1; i++)
	{
		if (compareWords(last_words[i], last_words[i+1]))
		{
			cout << last_words[i] << " and " << last_words[i+1] << endl;
			rhyme_counter += 1;
		}
	}
	
	// Calculate rhyme-line density
	double rhyme_density = rhyme_counter / (file_length * 1.0);

	// Print outputs according to how many rhymes were detected
	if (rhyme_counter > 1)
	{
		cout << fixed << setprecision(2);
		cout << "There are " << rhyme_counter << " pairs of rhyming words." << endl;
		cout << "There are " << file_length << " lines in this poem, so the rhyme-line density is: " << rhyme_density << endl;
	}
	else if (rhyme_counter == 1)
	{
		cout << fixed << setprecision(2);
		cout << "There is " << rhyme_counter << " pair of rhyming words." << endl;
		cout << "There are " << file_length << " lines in this poem, so the rhyme-line density is: " << rhyme_density << endl;
	}
	else if (rhyme_counter < 1)
	{
		cout << "No rhymes found." << endl;
		cout << "There are " << file_length << " lines in this poem." << endl;
	}


	// Close file for good, return memory to freestore, and assign pointer to Null	
	rhyme_stream.close();
	delete []last_words;
	last_words = nullptr;	

	return 0;
}

// Pre-condition: Input a string that you want to flip (passed by reference)
// Post-condition: The string's order is automatically flipped and physically changed by the function
void flipString(string &inputString)
{
	// Index string from last index to first index appending it to flippedString
        string flippedString = inputString;
        int len = inputString.length();
        for (int i = len - 1; i >= 0; i--)
                flippedString[len - 1 - i] = inputString[i];

        inputString = flippedString;
}

// Pre-condition: Input a string you want to physically clean (passed by reference)
// Post-condition: Physically changes input by stripping all non alphabetical characters and lowering the case of every letter
void cleanUp(string &word)
{
	string cleanWord = "";

	// Only appends alphabetical characters and lowers them
	for (unsigned int i = 0; i < word.size(); i++)
	{
		if (isalpha(word[i]))
			cleanWord += tolower(word[i]);
	}
	word = cleanWord;
}

// Pre-condition: Input a string (sentence from a poem in this program's usecase)
// Post-condition: Returns the last word in that string
string findLastWord(string line) {
	string reversedLine = line; 
	flipString(reversedLine); // Flips the string
    
	string lastWord = "";
	int i = 0;
	// Appends every character until a space is detected
	// String is flipped so finding the first word is actually finding the last word
	while (i < reversedLine.length() && !isspace(reversedLine[i])) {
        	lastWord += reversedLine[i];
        	i++;
    	}

    	flipString(lastWord); // Flip the word back to its original order
	cleanUp(lastWord); // Clean the word for later use
    	return lastWord;
}

// Pre-condition: Input two cleaned strings (all lower case and alphabetic characters)
// Post-condition: Returns true if the last two letters match, else returns false
bool compareWords(string word1, string word2)
{
	// Returns false if any line is smaller than 2
    	if (word1.size() < 2 || word2.size() < 2) {
        	return false;
    	}

	// Checks if the last two letters of both cleaned strings match
	if (word1[word1.size() - 1] == word2[word2.size() - 1] && word1[word1.size() - 2] == word2[word2.size() - 2])
		return true;
	
	return false;
}
