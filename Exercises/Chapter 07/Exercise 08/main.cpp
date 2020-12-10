/*
8. Redo Listing 7.15 without using the array class. Do two versions:

a. Use an ordinary array of const char * for the strings representing the season
names, and use an ordinary array of double for the expenses.

b. Use an ordinary array of const char * for the strings representing the season
names, and use a structure whose sole member is an ordinary array of
double for the expenses. (This design is similar to the basic design of the
array class.)
*/

#include <iostream>
#include <string>	

const int Seasons = 4;
const char* Snames[Seasons] =
{
	"Spring", "Summer", "Fall", "Winter"
};

struct Expenses
{
	double expenses[Seasons];
};

void fill1(double pa[]);
void show1(const double pa[]);

void fill2(Expenses* pa);
void show2(const Expenses pa);

int main()
{
	// double expenses[Seasons];

	// fill1(expenses);
	// show1(expenses);

	Expenses expenses;

	fill2(&expenses);
	show2(expenses);

	return 0;
}

void fill1(double pa[])
{
	using namespace std;

	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa[i];
	}
}

void show1(const double pa[])
{
	using namespace std;

	double total = 0.0;

	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << pa[i] << endl;
		total += pa[i];
	}

	cout << "Total Expenses: $" << total << endl;
}

void fill2(Expenses* pa)
{
	using namespace std;

	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> pa->expenses[i];
	}
}

void show2(const Expenses pa)
{
	using namespace std;

	double total = 0.0;

	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << pa.expenses[i] << endl;
		total += pa.expenses[i];
	}

	cout << "Total Expenses: $" << total << endl;
}