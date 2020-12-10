/*
6. Write a program that asks how many miles you have driven and how many gallons
of gasoline you have used and then reports the miles per gallon your car has gotten.
Or, if you prefer, the program can request distance in kilometers and petrol in liters
and then report the result European style, in liters per 100 kilometers.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the distance in kilometers: ";
	double distance;
	cin >> distance;

	cout << "Enter the petrol in liters: ";
	double petrol;
	cin >> petrol;

	double litersPer100Kilometers = petrol * 100.0 / distance;
	
	cout << "Its " << litersPer100Kilometers << " per 100 kilometers.\n";

	return 0;
}