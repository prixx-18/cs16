#include <iostream> // for cout, cin, endl
#include <cmath>    // for pow -- the only one you're allowed to use from this lib
#include <iomanip>  // for setprecision, setw -- the only ones you're allowed to use from this lib
using namespace std;

// FUNCTION DECLARATIONS: YOU MUST USE THESE (do not remove):
void bubbleSort(int *array, int size);
double average(int *array, int size);
double median(int* array, int size);
double stddev(int* array, int size);

int main() {
    // Sets the printing of floating-point numbers
    // to show only 2 places after the decimal point
    cout << fixed << showpoint;
    cout << setprecision(2);

    // MISSING CODE HERE (you can remove these comments)
	// Get the number of grades to be entered from user
    // Create a dynamic int array based on this information
    // Get the user to enter all the grades
    // Print results while calling the appropriate functions

    int *grades = nullptr;
    unsigned int size;
    cout << "Enter number of grades: ";
    cin >> size;
    if (size < 1){
	cerr << "Error!\n";
	exit(1);
    }

    grades = new int[size];
    cout << "Enter grades (each on a new line):" << endl;
    for (unsigned int i = 0; i < size; i++) {
        cin >> grades[i];
    }

    bubbleSort(grades, size);
    double mean = average(grades, size);
    double medVal = median(grades, size);
    double StdDev = stddev(grades, size);

    cout << "Here are some statistics:" << endl;
    cout << setw(9) << "Average: " << mean << endl;
    cout << setw(9) << "Median: " << medVal << endl;
    cout << setw(9) << "StdDev: " << StdDev << endl;

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

// MISSING FUNCTION DEFINITIONS HERE (you can remove these comments)
double average(int *array, int size)
{
	double sum = 0.0;
	for (int i = 0; i < size; i++)
		sum += *(array + i); 

	return sum / size;
}

double median(int* array, int size)
{
	if (size % 2 != 0){
		return *(array + (size / 2));
	} else {
		int mid1 = *(array + (size / 2));
		int mid2 = *(array + ((size / 2 ) - 1));
		return (mid1 + mid2) / 2.0;
	}
}

double stddev(int* array, int size){
	if (size == 1)
		return 0.0;

	double summand = 0.0;
	
	double mean = average(array, size);
	
	for (int i = 0; i < size; i++)
		summand += pow(*(array + i) - mean, 2);

	return pow((1.0 / (size - 1)) * summand, 0.5);

}
