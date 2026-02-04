#include <iostream>
using namespace std;

int checkit(int number1, int number2, int number3)
{
	if(number1 > number2 && number2 > number3)
	{
		cout << 1 << endl; 
	} else {
		cout << 0 << endl;
	}

	return 0;
}

int main()
{
	checkit(9,8, 2);

	return 0;
}
