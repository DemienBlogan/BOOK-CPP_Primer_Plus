/*
1. Consider the following class declaration:
class Cow 
{
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * ho, double wt);
	Cow(const Cow c&);
	~Cow();
	Cow & operator=(const Cow & c);
	void ShowCow() const; // display all cow data
};

Provide the implementation for this class and write a short program that uses all the
member functions.
*/

#include <iostream>

#include "Cow.h"

using std::cout;

int main()
{
	Cow emptyCow;

	cout << "Empty cow:\n";
	emptyCow.ShowCow();

	Cow betty{ "Betty", "IT", 123.53 };

	cout << "\nBetty cow:\n";
	betty.ShowCow();

	Cow copyCow{ betty };

	cout << "\nCopy cow:\n";
	copyCow.ShowCow();

	emptyCow = betty;

	cout << "\nEmpty cow after assignment:\n";
	emptyCow.ShowCow();

	return 0;
}