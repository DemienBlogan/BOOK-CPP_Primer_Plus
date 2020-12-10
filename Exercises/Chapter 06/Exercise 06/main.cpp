/*
6. Put together a program that keeps track of monetary contributions to the Society
for the Preservation of Rightful Influence. It should ask the user to enter the number
of contributors and then solicit the user to enter the name and contribution of
each contributor.The information should be stored in a dynamically allocated array
of structures. Each structure should have two members: a character array (or else a
string object) to store the name and a double member to hold the amount of the
contribution. After reading all the data, the program should display the names and
amounts donated for all donors who contributed $10,000 or more.This list should
be headed by the label Grand Patrons.After that, the program should list the
remaining donors.That list should be headed Patrons. If there are no donors in one
of the categories, the program should print the word “none.”Aside from displaying
two categories, the program need do no sorting.
*/

#include <iostream>
#include <string>

using namespace std;

struct Contributor
{
	string name;
	int amountContribution;
};

int main()
{
	cout << "Enter the number of contibutors: ";
	size_t amount;
	cin >> amount;

	if (amount == 0)
	{
		cout << "None\n";
		return 0;
	}

	Contributor* contributors = new Contributor[amount];

	for (size_t i = 0; i < amount; i++)
	{
		cout << "Contributor #" << i + 1 << ":\n";
		cout << "\tEnter the name: ";
		cin >> contributors[i].name;
		cout << "\tEnter the amount of contribution: ";
		cin >> contributors[i].amountContribution;
	}

	// Check Grand Patrons
	bool ifThereGrandPatrons = false;
	for (size_t i = 0; i < amount; i++)
	{
		if (contributors[i].amountContribution >= 10'000)
		{
			ifThereGrandPatrons = true;
			break;
		}
	}

	// Show Grand Patrons
	if (ifThereGrandPatrons)
	{
		cout << "Grand Patrons:\n";
		for (size_t i = 0; i < amount; i++)
			if (contributors[i].amountContribution >= 10'000)
				cout << contributors[i].name << " ($" << contributors[i].amountContribution << ")\n";
	}

	// Check Other Patrons
	bool ifThereOtherPatrons = false;
	for (size_t i = 0; i < amount; i++)
	{
		if (contributors[i].amountContribution < 10'000)
		{
			ifThereOtherPatrons = true;
			break;
		}
	}

	// Show Other Patrons
	if (ifThereOtherPatrons)
	{
		cout << "Other Patrons:\n";
		for (size_t i = 0; i < amount; i++)
			if (contributors[i].amountContribution < 10'000)
				cout << contributors[i].name << " ($" << contributors[i].amountContribution << ")\n";
	}

	delete[] contributors;

	return 0;
}