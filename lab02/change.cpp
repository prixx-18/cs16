// change.cpp
// By: Priyansh Nath
// Created on: Jan 15th

#include <iostream>

using namespace std;

void compute_coins(int amount)
{
	// Precondition: 0 < amount < 100
	
        int quarterCount(0), dimeCount(0), pennyCount(0);
        int remainingAmount = amount;
        bool preceding = false;
	
	// Check for valid input
        if (remainingAmount < 1 || remainingAmount > 99){
                cout << "Amount is out of bounds. Must be between 1 and 99." << endl;
                return;
        }
	
	// Assign highest amount of quarters possible, updating remainding amount
        quarterCount = remainingAmount / 25;
        remainingAmount %= 25;

	// Assign highest amount of dimes possible, updating remainding amount
        dimeCount = remainingAmount / 10;
        remainingAmount %= 10;

	// Assigning leftover amount (if any) to pennies
        pennyCount = remainingAmount / 1;

	// Check for plural vs. singular cent amount
        if (amount == 1)
                cout << amount << " cent can be given in";
        else
                cout << amount << " cents can be given in";

	// Check for plural vs. singular quarter amount
        if (quarterCount > 1){
                cout << " " << quarterCount << " quarters";
                preceding = true;
        }
        else if (quarterCount == 1){
                cout << " " << quarterCount << " quarter";
                preceding = true;
        }

	// Check for plural vs. singular dime amount and if comma is required
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

	// Check for plural vs. singular penny amount and if comma is required
        if (preceding && pennyCount >= 1)
                cout << ",";

        if (pennyCount > 1)
                cout << " " << pennyCount << " pennies";
        else if (pennyCount == 1)
                cout << " " << pennyCount << " penny";
	
        cout << ".\n";

	// Postcondition: The function prints out the number of quarters, dimes, and pennies needed to make the amount value.

}

int main()
{
 	int input;

	// Reprompt until user inputs 0
        while (true) {
                cout << "Enter number of cents (or zero to quit):" << endl;
                cin >> input;
                if (input == 0)
                        break;
                compute_coins(input);
        }

        return 0;
}
