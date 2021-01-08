/*
1. Write a short program that asks for your height in integer inches and then converts
your height to feet and inches. Have the program use the underscore character to
indicate where to type the response. Also use a const symbolic constant to represent
the conversion factor.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter your height (in inches):___\b\b\b";
	int height;
	cin >> height;

	const int INCHES_IN_FEET = 12;
	int feet = height / INCHES_IN_FEET;
	int inches = height % INCHES_IN_FEET;

	cout << "It is " << feet << " feet and " << inches << " inches.\n";

	return 0;
}
