/*
6. The CandyBar structure contains three members, as described in Programming
Exercise 5.Write a program that creates an array of three CandyBar structures, initializes
them to values of your choice, and then displays the contents of each structure.
*/

#include <iostream>
#include <string>
using namespace std;

struct CandyBar
{
	string name;
	double weight;
	int calories;
};

int main()
{
	const size_t SIZE = 3;
	CandyBar snack[SIZE] =
	{
		{ "Bounty", 2.4, 290 },
		{ "Snikers", 2.5, 140 },
		{ "Twix", 1.9, 210 }
	};

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Snack #" << i + 1 << ":\n";
		cout << "\tName: " << snack[i].name << endl;
		cout << "\tWeight: " << snack[i].weight << endl;
		cout << "\tCalories: " << snack[i].calories << endl;
	}

	return 0;
}