// arrays.cpp
// Priyansh Nath

// DO NOT MODIFY THESE NEXT 6 LINES - DO NOT ADD TO THEM
#include <iostream> // for cout, cin
#include <fstream>  // for ifstream
#include <cstdlib>  // for exit
using namespace std;
#include "headers.h"    // contains the function declarations
#include "constants.h"  // contains 4 global variables

int main( )
{
    // DO NOT MODIFY THESE NEXT 3 LINES - DO NOT ADD TO THEM
    ifstream ifs;
    int size = MAXSIZE, array[MAXSIZE];
    getArray(ifs, FILENAME, array, size);


    print_array(array, size); // Directly print's arrays contents
    int max = maxArray(array, size); // Finds max value in array
    int min = minArray(array, size); // Finds min value in array
    int sum = sumArray(array, size); // Calculates sum of array

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;
    cout << "Sum = " << sum << endl;
    evensArray(array, size); // Finds and prints all even elements
    primesArray(array, size); // Finds and prints all prime number elements
    AllSearches(array, size); // Cross references input array and global array SEARCHES to print which elements are found in both

    return 0;
}

