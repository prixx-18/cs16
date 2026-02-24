// File: sfunctions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "sheaders.h"

// Pre-condition: 
// 	Param 1: boolean value for descending (input 1 or true) or ascending (input 0 or false)
// 	Param 2: array of integers that you want to sort 
// 	Param 3: integer index you want to start searching from 
// 	Param 4: integer indicating end index of search
// Post-condition: Returns the index of the lowest value (if ascending is desired) or highest value (if descending is desired)
int find_index_of_swap(bool desc, int a[], int start_index, int number_used)
{
	int index = start_index;
	if (!desc) // Ascending case
	{
		for (int i = start_index; i < number_used; i++)
		{
			if (a[i] < a[index]) // Search for smallest number
				index = i;	
		}
	}
	else // Descending case
	{
		for (int i = start_index; i < number_used; i++)
                {
                        if (a[i] > a[index]) // Search for largest number
                                index = i;
                }
	}

	return index;
}

// Pre-condition: enter two integer values (passed by reference)
// Post-condition: the value of the two integers are directly swapped (changes persist outside of function)
void swap_values(int &num1, int &num2)
{
	int temp = num1; // temporarily store num1 in temp
	num1 = num2;
	num2 = temp;
}

// Pre-condition:
//      Param 1: boolean value for descending (input 1 or true) or ascending (input 0 or false)
//      Param 2: array of integers that you want to sort
//      Param 3: integer indicating end index of search
//      Param 4: integer index you want to start searching from
// Post-condition: Internally calles found_index_of_swap and swap_values to sort given array in descending or ascending order selection sort style      
void sort(bool desc, int a[], int number_used, int index)
{
	if (index >= number_used - 1) // Base case: If start of search index equals end of search index there is nothing to search 
		return;
	else // Recursive case: Swap element in found index with current search index and recursively call sort
	{
		int found_index = find_index_of_swap(desc, a, index, number_used);
		swap_values(a[index], a[found_index]);
		sort(desc, a, number_used, index + 1);
	}
}

// Pre-condition: Pass in an ifstream object by reference and the file name as a string
// Post-condition: Function returns the length of the file as an integer
int getFileSize(ifstream &sort_stream, string file_name)
{
	sort_stream.open(file_name);
	int next, file_length(0);
	while (sort_stream >> next)
		file_length++;
	sort_stream.close();
	return file_length;
}

// Pre-condition: Pass in an ifstream object, file name as a string (file contains integers), array of integers, and the length of the file as an integer
// Post-condition: Reads and transfers all numbers from a file into an array
void getArray(ifstream &sort_stream, string file_name, int a[], int file_length) 
{
    sort_stream.open(file_name);
    for (int i = 0; i < file_length; i++) 
        sort_stream >> a[i]; // Read directly from file into the array
    sort_stream.close();
}

