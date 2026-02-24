// File: pfunctions.cpp
#include <iostream>
#include <string> 
using namespace std;

#include "pheaders.h"

// DEFINE THE 2 FUNCTIONS PER THE pheaders.h FILE HERE
// Add Pre- and Post-Condition comments

// Pre-condition: Input a cleaned string (only alphabetical and lower case)
// Post-condition: Checks if the string is the same forward and backward (palindrome)
bool isPalindrome(string s)
{
        if (s.size() <= 1) // Base case: If string is one character long or less after surviving all false checks
                return true;

        else{
                if (s[0] != s[s.size() - 1]) // Check for any sign of no palindrome
                        return false;

                return isPalindrome(s.substr(1, s.size() - 2)); // Recursive case: Recursively compare first and last letter of truncated strings
        }
}

// Pre-condition: Input a string you want to physically clean (passed by reference)
// Post-condition: Physically changes input by stripping all non alphabetical characters and lowering the case of every letter
void cleanUp(string &s)
{
        string cleanWord = "";

        // Only appends alphabetical characters and lowers them
        for (unsigned int i = 0; i < s.size(); i++)
        {
                if (isalpha(s[i]))
                        cleanWord += tolower(s[i]);
        }
        s = cleanWord;
}
