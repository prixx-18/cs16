#include <iostream>

using namespace std;

void compute_coins(int amount) 
{
	
	int quarterCount(0), dimeCount(0), pennyCount(0);
	int remainingAmount = amount;
	bool preceding = false;

	if (remainingAmount < 1 || remainingAmount > 99){
		cout << "Amount is out of bounds. Must be between 1 and 99." << endl;
		return;
	}


	quarterCount = remainingAmount / 25;
	remainingAmount %= 25;

	dimeCount = remainingAmount / 10;
	remainingAmount %= 10;

	pennyCount = remainingAmount / 1;
	
	if (amount == 1)
		cout << amount << " cent can be given in";
	else 
		cout << amount << " cents can be given in";

	if (quarterCount > 1){
		cout << " " << quarterCount << " quarters";
		preceding = true;
	}
	else if (quarterCount == 1){
		cout << " " << quarterCount << " quarter";
		preceding = true;
	}

	if (preceding && dimeCount >= 1)
		cout << ",";
	
	if (dimeCount > 1){
		cout << " " << dimeCount << " dimes";
		preceding = true;
	}
	else if (dimeCount == 1){
		cout << " " << dimeCount << " dime";
		preceding = true;
	}

	if (preceding && pennyCount >= 1)
		cout << ",";

	if (pennyCount > 1)
		cout << " " << pennyCount << " pennies";
	else if (pennyCount == 1)
		cout << " " << pennyCount << " penny";

	cout << ".\n";

}

int main()
{
	int input;
	while (true) {
		cout << "Enter number of cents (or 0 to quit):" << endl;
		cin >> input;
		if (input == 0)
			break;
		compute_coins(input);
	}
	
	return 0;
}
