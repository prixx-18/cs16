// file: r_functions.cpp
// YOUR NAME HERE
// Define the functions, per the list in r_headers.h
void NameSort(UndergradStudents array[], int size)
{
        for (int i = size - 1; i >= 0; i--)
        {
                UndergradStudents temp;
                for (int j = 1; j <= i; j++)
                {
                        if (array[j-1].lastName > array[j].lastName)
                        {
                                temp = array[j-1];
                                array[j-1] = array[j];
                                array[j] = temp;
                        }
                }
        }
}

void InitializeStructures(UndergradStudents us[], int &size)
{
        int arrCounter = 0;
        while (arrCounter < 20)
        {
                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter first name (or x to quit): ";
                cin >> us[arrCounter].firstName;
                if (us[arrCounter].firstName == "x" || us[arrCounter].firstName == "X")
                        break;

                 cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter last name: ";
                cin >> us[arrCounter].lastName;

                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter major: ";
                cin >> us[arrCounter].major;

                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter GPA Year 1: ";
                cin >> us[arrCounter].GPA1;

                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter GPA Year 2: ";
                cin >> us[arrCounter].GPA2;

                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter GPA Year 3: ";
                cin >> us[arrCounter].GPA3;

                cout << "Student ";
                if (arrCounter < 10)
                        cout << "0";
                cout << arrCounter + 1 << ":Enter GPA Year 4: ";
                cin >> us[arrCounter].GPA4;

                us[arrCounter].ID = arrCounter;

                cout << endl;
                arrCounter++;
        }

        size = arrCounter; // In case user added more entries than expected (still must be less than 20)
}

void WriteResults(ofstream &outf, UndergradStudents us[], int size)
{
        outf.open(OUTPUTFILE);

        cout << fixed << setprecision(2);
        outf << fixed << setprecision(2);

        outf << "These are the results sorted by last name:" << endl;
        for (int i = 0; i < size; i++)
        {
                float averageGPA = (us[i].GPA1 + us[i].GPA2 + us[i].GPA3 + us[i].GPA4) / 4.0;
                outf << "ID# " << us[i].ID << ": " << us[i].firstName << ": " << us[i].major << ": " << averageGPA << endl;
        }

        outf.close();
}
