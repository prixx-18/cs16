#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Note: ifstream and ofstream objects
//       have to be passed in by ref in functions
// DO NOT change this declaration!
vector<int> SeqSearchAll (int target, ifstream &ifs);

int main() {
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    int target;
    cout << "Enter target: ";
    cin >> target;

    vector<int> returned = SeqSearchAll (target, ifs);
    ifs.close();

    if (returned[0] == -1)
        cout << "Target not found!\n";
    else {
        cout << "Target found at position(s): ";
        for (int i = 0; i < returned.size(); i++) {
            cout << returned[i] << " ";
        } // for
        cout << endl;
    } // else
    return 0;
}

// Pre-condition: Pass in an integer that you want to find and an ifstream object that creates a stream to a desired file
// Post-condition: The function will return a vector of type int with every index the target int was found within the file
vector<int> SeqSearchAll (int target, ifstream &ifs)
{
	vector<int> seqSearch, match;
	int next;

	while (ifs >> next)
		seqSearch.push_back(next);

	for (unsigned int i = 0; i < seqSearch.size(); i++)
	{
		if (seqSearch[i] == target)
			match.push_back(i);
	}

	if (match.size() == 0)
		match.push_back(-1);

	return match;
}
