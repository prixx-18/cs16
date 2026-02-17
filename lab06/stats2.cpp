#include <iostream> // for cout, cin, endl
#include <cmath>    // for pow -- the only one you're allowed to use from this lib
#include <iomanip>  // for setprecision, setw -- the only ones you're allowed to use from this lib
#include <fstream>
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);

int main()
{
	// Sets the printing of floating-point numbers
    	// to show only 2 places after the decimal point
	cout << fixed << showpoint;
	cout << setprecision(2);

	// Initialize int pointer pointing to Null so it's not dangling    
	int *grades = nullptr, next, fileSize = 0;
	ifstream gradeStream;
	string fileName;

	cout << "Enter filename: ";
	cin >> fileName;
	gradeStream.open(fileName);

	 // Reject sizes less than 1
        if (gradeStream.fail()){
                cerr << "Cannot open " << fileName << endl;
                exit(1);
        }

	while (gradeStream >> next)
		fileSize++;

	gradeStream.close();

	gradeStream.open(fileName);
	
	// Create dynamic array in freestore/heap and have user enter each element
	grades = new int[fileSize];
	for (unsigned int i = 0; i < fileSize; i++) {
        	gradeStream >> next;
		grades[i] = next;
    	}

	// Call bubbleSort to sort the array and average, median, and stddev to calculate respective stats
	bubbleSort(grades, fileSize);
	double mean = average(grades, fileSize);
	double medVal = median(grades, fileSize);
	double StdDev = stddev(grades, fileSize);
	
	// Print statistics and align using setw()
	cout << "Here are some statistics:" << endl;
	cout << setw(9) << "N: " << fileSize << endl;
	cout << setw(9) << "Average: " << mean << endl;
	cout << setw(9) << "Median: " << medVal << endl;
	cout << setw(9) << "StdDev: " << StdDev << endl;

	// Delete dynamic array to return mem to heap and prevent mem leaks. Reassign pointer to Null
	delete []grades;
	grades = nullptr;

	return 0;
}

// This is bubbleSort - it is given for you to use.
// Pre-Condition:: It takes in a dynamic int array and its size
// Post-Condition: It sorts the array in ascending order of its values
void bubbleSort(int *array, int size) {
  int temp;
  for (int i = size-1; i >= 0; i--) {
    for (int j = 1; j <= i; j++) {
      if (array[j-1] > array[j]) {
        temp = array[j-1];
        array[j-1] = array[j];
        array[j] = temp;
      } // if
    } // for j
  } // for i
}

// Pre-condition: Takes in a pointer to an array (dynamic for this code) and the array size
// Post-condition: Returns the mean value of the array as a double 
double average(int *array, int size)
{
	double sum = 0.0; // Force floating point math
	for (int i = 0; i < size; i++)
		sum += *(array + i); 

	return sum / size;
}

// Pre-condition: Takes in a pointer to an array (dynamic for this code) and the array size
// Post-condition: Returns the median value of the array as a double
double median(int* array, int size)
{
	if (size % 2 != 0){ 
		return *(array + (size / 2)); // Return the middle value of an odd sized array
	} else {
		int mid1 = *(array + (size / 2));
		int mid2 = *(array + ((size / 2 ) - 1));
		return (mid1 + mid2) / 2.0; // Return the average of the two middle numbers in an even sized array
	}
}

// Pre-condition: Takes in a pointer to an array (dynamic for this code) and the array size
// Post-condition: Returns the standard deviation value of the array as a double
double stddev(int* array, int size)
{
	// stddev is always 0 when size is 1
	if (size == 1)
		return 0.0;

	double summand = 0.0;
	
	// Call average to use mean in stddev calculations
	double mean = average(array, size);
	
	// Add every element's euclidean distance from mean to simulate summation
	for (int i = 0; i < size; i++)
		summand += pow(*(array + i) - mean, 2);

	// Raise to power of 0.5 to square root the expression
	return pow((1.0 / (size - 1)) * summand, 0.5);

}
