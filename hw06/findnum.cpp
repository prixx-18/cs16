#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int FindNum(ifstream &ifs);

int main() {
    ifstream ifs;
    string fname;
    cout << "Enter filename: ";
    cin >> fname;
    ifs.open(fname);

    // find the 2nd largest int and print it
    cout << FindNum(ifs) << endl;
    
    ifs.close();
    return 0;
}

// Pre-condition: Pass in an ifstream object by reference
// Post-Condition: The function finds and returns the second largest int within file the ifstream connects to
int FindNum(ifstream &ifs)
{
        vector<int> nums;
        int next, max1, max2;

        while (ifs >> next)
                nums.push_back(next);

        if (nums[1] >= nums[0])
        {
                max1 = nums[1];
                max2 = nums[0];
        }
        else
        {
                max1 = nums[0];
                max2 = nums[1];
        }

        for (unsigned int i = 2; i < nums.size(); i++)
        {
                if (nums[i] > max1)
                {
                        max2 = max1;
                        max1 = nums[i];
                }
                else if (nums[i] < max1 && nums[i] > max2)
                        max2 = nums[i];
        }

        return max2;
}
