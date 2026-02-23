/* Main function for selectionSort.cpp
 * For use in CS 16
 * (c) 2024 by Z.Matni
 */
#include <iostream> // for cout, cin, endl
#include <fstream>  // for ifstream
#include <string>   // for string
#include <cstdlib>  // for exit
using namespace std;
#include "sheaders.h"

int main() {
    	// 1. Get filename from user and check it
	ifstream sort_stream;
	string file_name;
	cout << "Enter filename: ";
	getline(cin, file_name);

	sort_stream.open(file_name);
	if (sort_stream.fail())
		exit(1);
	sort_stream.close();

    	// 2. Get size of file to then create dynamic array
    	//      Note: You HAVE to use the functions:
    	//      getFileSize() and getArray() here
	int file_size = getFileSize(sort_stream, file_name);

	int *sort_array = new int[file_size];
	getArray(sort_stream, file_name, sort_array, file_size);

    	// 3. Print original array (see PDF lab description for details)
	for (int i = 0; i < file_size; i++)
    		cout << sort_array[i] << " ";
    	cout << endl;
    	// 4. Ask user for ascending or descending sort
	bool desc;
	cout << "Ascending (0) or Descending (1): ";
	cin >> desc;
    	// 5. Run selection sort on the array
    	//      Note: You HAVE to use the function sort() here
	sort(desc, sort_array, file_size, 0);
    	// 6. Print sorted array (see PDF lab description for details)
	for (int i = 0; i < file_size; i++) 
		cout << sort_array[i] << " ";
	cout << endl;

	delete[] sort_array;
    	sort_array = nullptr;

    	return 0;
}
