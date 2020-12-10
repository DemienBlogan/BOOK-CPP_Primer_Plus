/*
2. Do Programming Exercise 1 but use dynamic memory allocation instead of fixedsize
arrays for the various strings tracked by the two classes.
*/

#include <iostream>
#include "classic.h" // which will contain #include cd.h

using namespace std;

void Bravo(const Cd& disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	classic c2 = classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
	Cd* pcd = &c1;

	cout << "Using object directly:\n";
	c1.Report(); // use Cd method
	c2.Report(); // use Classic method

	cout << "Using type cd * pointer to objects:\n";
	pcd->Report(); // use Cd method for cd object
	pcd = &c2;
	pcd->Report(); // use Classic method for classic object

	cout << "Calling a function with a Cd reference argument:\n";
	Bravo(c1);
	Bravo(c2);

	cout << "Testing assignment: ";
	classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd& disk)
{
	disk.Report();
}