// functions.cpp
// Priyansh Nath

// DO NOT MODIFY THESE NEXT 5 LINES - DO NOT ADD TO THEM
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// INCLUDE HEADER FILE(S) HERE:
#include "headers.h"
#include "constants.h"

// The following function is defined for you. ***Do not change it AT ALL.***
//
// Pre-Condition: takes in an ifstream object for input file, 
//              a string for an input filename, an integer array and its size
// Post-Condition: the array will be populated with all the numbers from the input file
void getArray(ifstream& in, string fname, int arr[], int size)
{
    in.open(fname);
    if ( in.fail() ) 
    { 
        cerr << "Input file opening failed.\n"; 
        exit(1); 
    }
    for (int i = 0; i < size; i++)
    {
        in >> arr[i];
    }
}


// Pre-Condition: takes in an integer array and its size
// Post-Condition: prints all elements in the array.
void print_array(int arr[], int asize)
{
	for (int i = 0; i < asize; i++) // iterates over every element to print it
	{
		if (i == asize - 1) // only include comma if there is a following element
			cout << arr[i];
		else
			cout << arr[i] << ", "; 
	}
	cout << endl;
}

// Pre-Condition: takes in an integer array and its size.
// Post-Condition: returns the maximum number in the array
int maxArray(int arr[], int asize)
{
	int max = arr[0]; // Initialize max to element at index 0
	for (int i = 0; i < asize; i++)
	{
		if (arr[i] > max) // Updates max if element is greater than previous element
			max = arr[i];
	}
	return max;
}


// Pre-Condition: takes in an integer array and its size.
// Post-Condition: returns the minimum number in the array.
int minArray(int arr[], int asize)
{
	int min = arr[0]; // Initializes min to element at index 0
	for (int i = 0; i < asize; i++)
	{
		if (arr[i] < min) // Updates min if elemet is less than previous element
			min = arr[i];
	}
	return min;
}


// Pre-Condition: takes in an integer array and its size.
// Post-Condition: returns the sum of the array.
int sumArray(int arr[], int asize)
{
	int sum = 0; // Initializes sum to 0
	for (int i = 0; i < asize; i++)
		sum += arr[i];
	return sum;
}


// Pre-Condition: takes in an integer array and its size.
// Post-Condition: prints all the even numbers in the array.
void evensArray(int arr[], int asize)
{
	cout << "Evens: ";
	for (int i = 0; i < asize; i++)
	{
		if (arr[i] % 2 == 0) // Only prints element if element divided by 2 has no remainder
			cout << arr[i] << ", ";
	}
	cout << "end" << endl;
}

// Pre-Condition: takes in an integer array and its size
// Post-Condition: prints all the prime numbers in the array.
void primesArray(int arr[], int asize)
{
	cout << "Primes: ";
        
        for (int i = 0; i < asize; i++)
	{
		if (arr[i] <= 1) continue; // Bypasses 1, 0, and negative numbers
		bool isPrime = true; // Element is assumed to be prime until proven otherwise
		for (int j = 2; j * j <= arr[i]; j++) // Only check numbers until square root of element
		{
                	if (arr[i] % j == 0)
			{
                    		isPrime = false;
                    		break;
                	}
	    	}
		if (isPrime)
                	cout << arr[i] << ", ";
        }
        cout << "end" << endl;
}


// Pre-Condition: takes in an integer array, its size, and an int target.
//                  This function must be called within AllSearches().
// Post-Condition: if the function finds "target", it returns its index in the array, otherwise it returns -1.
//                  the function only takes ONE integer (at a time) when searching.
int SeqSearch(int arr[], int array_size, int target)
{
	int index = -1; // Default return value
	for (int i = 0; i < array_size; i++)
	{
		if (arr[i] == target)
		{
			index = i;
			break;
		}
	}

	return index;
}

// Pre-Condition: runs a loop of SeqSearch() of an array, given the array and its size.
//                  This function has to call on SeqSearch() function.
// Post-Condition: outputs either of the following for every iteration of the loop:
//              Looking for <search parameter>. Not found
//              Looking for <search parameter>. Found at index: <index value>	                  
void AllSearches(int array[], int array_size)
{	
	cout << "Searches:" << endl;

	for (int i = 0; i < NSEARCHES; i++)
	{
		int index = SeqSearch(array, array_size, SEARCHES[i]); // Calling SeqSearch to iterate and check if array includes the target
		if (index == -1)
			cout << "Looking for " << SEARCHES[i] << ". Not Found!" << endl;
		else
			cout << "Looking for " << SEARCHES[i] << ". Found at index: " << index << endl;
	}
}
