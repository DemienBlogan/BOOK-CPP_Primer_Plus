/*
7. A Betelgeusean plorg has these properties:
Data
A plorg has a name with no more than 19 letters.
A plorg has a contentment index (CI), which is an integer.

Operations
A new plorg starts out with a name and a CI of 50.
A plorg’s CI can change.
A plorg can report its name and CI.
The default plorg has the name "Plorga".

Write a Plorg class declaration (including data members and member function prototypes)
that represents a plorg.Write the function definitions for the member functions.
Write a short program that demonstrates all the features of the Plorg class.
*/

#include <iostream>

#include "Plorg.h"

using std::cout;

int main()
{
	Plorg plorg1;

	cout << "Plorg #1:\n";
	plorg1.Report();

	cout << "Plorg #1 after change:\n";
	plorg1.ChangeCI(100);
	plorg1.Report();

	cout << "Plorg #2:\n";
	Plorg plorg2{ "Demien" };
	plorg1.Report();

	return 0;
}