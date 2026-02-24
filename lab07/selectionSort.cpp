#include <iostream> // for cout, cin, endl
#include <fstream>  // for ifstream
#include <string>   // for string
#include <cstdlib>  // for exit
using namespace std;
#include "sheaders.h"

int main() {
    	// Get filename from user and store it in file_name
	ifstream sort_stream;
	string file_name;
	cout << "Enter filename: ";
	cin >> file_name;

	// Check if file successfully opens
	sort_stream.open(file_name);
	if (sort_stream.fail())
		exit(1);
	sort_stream.close();

    	// Get file size, initialize dynamic array, and read file data into array
	int file_size = getFileSize(sort_stream, file_name);

	int *sort_array = new int[file_size];
	getArray(sort_stream, file_name, sort_array, file_size);

    	// Print original array for comparison
	cout << "Original array:" << endl;
	for (int i = 0; i < file_size; i++)
    		cout << sort_array[i] << " ";
    	cout << endl;

    	// Prompt user for ascending or descending
	bool desc;
	cout << "Ascending (0) or Descending (1): ";
	cin >> desc;

    	// Call sort
	sort(desc, sort_array, file_size, 0);

    	// Print sorted array
	cout << "Sorted array:" << endl;
	for (int i = 0; i < file_size; i++) 
		cout << sort_array[i] << " ";
	cout << endl;

	// Delete dynamic array to return memory back to heap and reassign int array ptr to Null
	delete[] sort_array;
    	sort_array = nullptr;

    	return 0;
}
