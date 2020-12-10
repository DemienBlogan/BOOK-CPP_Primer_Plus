/*
9. Do Programming Exercise 6 but modify it to get information from a file.The first
item in the file should be the number of contributors, and the rest of the file should
consist of pairs of lines, with the first line of each pair being a contributor’s name
and the second line being a contribution.That is, the file should look like this:

4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Contributor
{
	string name;
	int amountContribution;
};

int main()
{
	ifstream file("Contributors.txt");

	if (!file)
	{
		cout << "File 'Contributors.txt' could not been opened.\n";
		return 1;
	}

	size_t amount;
	file >> amount;
	file.ignore();

	if (amount == 0)
	{
		cout << "None\n";
		return 0;
	}

	Contributor* contributors = new Contributor[amount];

	for (size_t i = 0; i < amount; i++)
	{
		getline(file, contributors[i].name);
		file >> contributors[i].amountContribution;
		file.ignore();
	}

	file.close();

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