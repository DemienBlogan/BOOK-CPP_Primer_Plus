/*
2. This exercise is the same as Programming Exercise 1, except that you should use private
inheritance instead of containment.Again, a few typedefs might prove handy.
Also you might contemplate the meaning of statements such as the following:
PairArray::operator=(PairArray(ArrayInt(),ArrayInt()));
cout << (const string &)(*this);

The class should work with the same test program as shown in Programming
Exercise 1.
*/

#include <iostream>
#include <string>
#include "Wine.h"

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	cout << "Enter name of wine: ";
	std::string label;
	getline(std::cin, label);

	cout << "Enter number of years: ";
	int years;
	cin >> years;

	Wine holding(label.c_str(), years);

	holding.GetBottles();
	holding.Show();

	const int YEARS = 3;
	int yearsArray[YEARS] = { 1993, 1995, 1998 };
	int bottlesArray[YEARS] = { 48, 60, 72 };

	Wine more("Gushing Grape Red", YEARS, yearsArray, bottlesArray);

	more.Show();

	cout << "Total bottles for " << more.Label() << ": " << more.sum() << endl;

	cout << "Bye\n";

	return 0;
}