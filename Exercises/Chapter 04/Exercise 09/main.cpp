/*
9. Do Programming Exercise 6, but instead of declaring an array of three CandyBar
structures, use new to allocate the array dynamically.
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
	CandyBar* snack = new CandyBar[SIZE]
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