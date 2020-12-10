/*
2. The CandyBar structure contains three members.The first member holds the brand
name of a candy bar.The second member holds the weight (which may have a fractional
part) of the candy bar, and the third member holds the number of calories
(an integer value) in the candy bar.Write a program that uses a function that takes
as arguments a reference to CandyBar, a pointer-to-char, a double, and an int and
uses the last three values to set the corresponding members of the structure.The last
three arguments should have default values of “Millennium Munch,” 2.85, and 350.
Also the program should use a function that takes a reference to a CandyBar as an
argument and displays the contents of the structure. Use const where appropriate.
*/

#include <iostream>
#include <cstring>

using namespace std;

struct CandyBar
{
	char name[30];
	double weight;
	int calories;
};

void SetCandyBar(CandyBar& bar, const char* name = "Millennium Munch", double weight = 2.85, int calories = 350);
void ShowCandyBar(const CandyBar& bar);

int main()
{
	CandyBar bar;

	SetCandyBar(bar);
	ShowCandyBar(bar);

	return 0;
}

void SetCandyBar(CandyBar& bar, const char* name, double weight, int calories)
{
	strcpy_s(bar.name, 30, name);
	bar.weight = weight;
	bar.calories = calories;
}

void ShowCandyBar(const CandyBar& bar)
{
	cout << "Name: " << bar.name << endl;
	cout << "Weight: " << bar.weight << endl;
	cout << "Calories: " << bar.calories << endl;
}