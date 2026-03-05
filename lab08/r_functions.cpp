// file: r_functions.cpp
// Priyansh Nath

// Pre-condition: Enter an array of type UndergradStudents and its size
// Post-condition: Sorts the array by last name
void NameSort(UndergradStudents array[], int size)
{
	// Employs bubble sort algorithm
        for (int i = size - 1; i >= 0; i--)
        {
                UndergradStudents temp;
                for (int j = 1; j <= i; j++)
                {
			// If the ASCII value of the previous element is greater than target element... swap
                        if (array[j-1].lastName > array[j].lastName)
                        {
                                temp = array[j-1];
                                array[j-1] = array[j];
                                array[j] = temp;
                        }
                }
        }
}

// Pre-condition: Enter an array of type UndergradStudents and its size
// Post-condition: Creates and Initializes UndergradStudent objects into an array
void InitializeStructures(UndergradStudents us[], int &size)
{	
        cout << "STUDENT RECORDS:" << endl;

	// Ensures array stays under 20 elements
	int arrCounter = 0;
        while (arrCounter < 20)
        {
		// Takes and initializes first name
		cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter first name (or x to quit): ";
                cin >> us[arrCounter].firstName;
                if (us[arrCounter].firstName == "x" || us[arrCounter].firstName == "X")
                        break;

		// Takes and initializes last name
                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter last name: ";
                cin >> us[arrCounter].lastName;

		// Takes and initializes major
                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter major: ";
                cin >> us[arrCounter].major;

		// Takes and initializes year 1 GPA
                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter GPA Year 1: ";
                cin >> us[arrCounter].GPA1;

		// Takes and initializes year 2 GPA
                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter GPA Year 2: ";
                cin >> us[arrCounter].GPA2;

		// Takes and initializes year 3 GPA
                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter GPA Year 3: ";
                cin >> us[arrCounter].GPA3;

		// Takes and initializes year 4 GPA
                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter GPA Year 4: ";
                cin >> us[arrCounter].GPA4;

		// Automatically assignes ID based on inputting order
                us[arrCounter].ID = arrCounter + 1;

                cout << endl;
                arrCounter++;
        }

        size = arrCounter; // In case user added more entries than expected (still must be less than 20)
}

// Pre-condition: Takes in an outstream object (by reference), array of type UndergradStudents, and array size
// Post-condition: Prints out the array
void WriteResults(ofstream &outf, UndergradStudents us[], int size)
{
	// Opens output file with outstream object
        outf.open(OUTPUTFILE);

	// Sets precision of GPA averages to 2
        cout << fixed << setprecision(2);
        outf << fixed << setprecision(2);
	
	// Calls NameSort
	NameSort(us, size);

        outf << "These are the results sorted by last name:" << endl;
        for (int i = 0; i < size; i++)
        {
                float averageGPA = (us[i].GPA1 + us[i].GPA2 + us[i].GPA3 + us[i].GPA4) / 4.0;
                outf << "ID# " << us[i].ID << ": " << us[i].lastName << ": " << us[i].firstName << ": " << us[i].major << ": " << averageGPA << endl;
        }

        outf.close();
}
