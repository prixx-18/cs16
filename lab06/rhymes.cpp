// Include statements go here...
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// FUNCTION DECLARATIONS: YOU MUST DEFINE AND USE THESE (do not remove):
//      You can declare/define other functions if you like as well,
//      but you must use the 3 functions below.
// See lab description for more on these functions.

void flipString(string &inputString);
string findLastWord(string line);
void cleanUp(string &word);
bool compareWords(string word1, string word2);

int main() 
{
	ifstream rhyme_stream;
	string file_name;
	
	cout << "Enter filename: ";
	cin >> file_name;
	rhyme_stream.open(file_name);

	if (rhyme_stream.fail())
	{
		cerr << "Cannot open " << file_name << endl;
		exit(1);
	}

	int file_length = 0;

	string temp;
	while (getline(rhyme_stream, temp)) {
    		file_length++;
	}

	rhyme_stream.close();

	// 2. Reopen it immediately using the same file name
	rhyme_stream.open(file_name);

	string *last_words = new string[file_length];
	
	for (unsigned int i = 0; i < file_length; i++)
	{
		string poem_line;
		getline(rhyme_stream, poem_line);
		string last_word = findLastWord(poem_line);
		last_words[i] = last_word;
	}

	int rhyme_counter = 0;
	for (unsigned int i = 0; i < file_length - 1; i++)
	{
		if (compareWords(last_words[i], last_words[i+1]))
		{
			cout << last_words[i] << " and " << last_words[i+1] << endl;
			rhyme_counter += 1;
		}
	}
	
	double rhyme_density = rhyme_counter / (file_length * 1.0);
	
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
	else
	{
		cout << "No rhymes found." << endl;
		cout << "There are " << file_length << " lines in this poem." << endl;
	}
		
	rhyme_stream.close();
	delete []last_words;
	last_words = nullptr;	

	return 0;
}

void flipString(string &inputString)
{
        string flippedString = inputString;
        int len = inputString.length();
        for (int i = len - 1; i >= 0; i--)
                flippedString[len - 1 - i] = inputString[i];

        inputString = flippedString;
}

void cleanUp(string &word)
{
	string cleanWord = "";
	for (unsigned int i = 0; i < word.size(); i++)
	{
		if (isalpha(word[i]))
			cleanWord += tolower(word[i]);
	}
	word = cleanWord;
}

string findLastWord(string line) {
	string reversedLine = line; 
	flipString(reversedLine); // Assume this function reverses the string
    
	string lastWord = "";
	int i = 0;
	// Check bounds (i < size) and look for whitespace
	while (i < reversedLine.length() && !isspace(reversedLine[i])) {
        	lastWord += reversedLine[i];
        	i++;
    	}

    	flipString(lastWord); // Flip the word back to its original order
	cleanUp(lastWord);
    	return lastWord;
}

bool compareWords(string word1, string word2)
{
	// Safety check for blank lines or single-character noise
    	if (word1.size() < 2 || word2.size() < 2) {
        	return false;
    	}

	if (word1[word1.size() - 1] == word2[word2.size() - 1] && word1[word1.size() - 2] == word2[word2.size() - 2])
		return true;
	
	return false;
}
