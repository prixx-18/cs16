// File: sfunctions.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

#include "sheaders.h"

// DEFINE ALL 5 FUNCTIONS PER THE sheaders.h FILE HERE
// Add Pre- and Post-Condition comments
//

int find_index_of_swap(bool desc, int a[], int start_index, int number_used)
{
	int index = start_index;
	if (!desc)
	{
		for (int i = start_index; i < number_used; i++)
		{
			if (a[i] < a[index])
				index = i;	
		}
	}
	else
	{
		for (int i = start_index; i < number_used; i++)
                {
                        if (a[i] > a[index])
                                index = i;
                }
	}

	return index;
}

void swap_values(int &num1, int &num2)
{
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void sort(bool desc, int a[], int number_used, int index)
{
	if (index >= number_used - 1)
		return;
	else
	{
		int found_index = find_index_of_swap(desc, a, index, number_used);
		swap_values(a[index], a[found_index]);
		sort(desc, a, number_used, index + 1);
	}
}

int getFileSize(ifstream &sort_stream, string file_name)
{
	sort_stream.open(file_name);
	int next, file_length(0);
	while (sort_stream >> next)
		file_length++;
	sort_stream.close();
	return file_length;
}

void getArray(ifstream &sort_stream, string file_name, int a[], int file_length) 
{
    sort_stream.open(file_name);
    for (int i = 0; i < file_length; i++) 
        sort_stream >> a[i]; // Read directly from file into the array
    sort_stream.close();
}

