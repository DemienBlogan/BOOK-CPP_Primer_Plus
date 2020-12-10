/*
6. Do Programming Exercise 5 but use a two-dimensional array to store input for 3
years of monthly sales. Report the total sales for each individual year and for the
combined years.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	const size_t MONTH_SIZE = 12;
	const string MONTHS[MONTH_SIZE] =
	{
		"January", "February", "March", "April",
		"May", "June", "July", "August",
		"September", "October", "November", "December"
	};

	const size_t YEARS = 3;
	int monthSales[YEARS][MONTH_SIZE];

	for (size_t i = 0; i < YEARS; i++)
	{
		cout << "Year #" << i + 1 << ":\n";

		for (size_t j = 0; j < MONTH_SIZE; j++)
		{
			cout << "\tEnter amount of sales in " << MONTHS[j] << ": ";
			cin >> monthSales[i][j];
		}
	}

	int yearSales = 0;	

	for (size_t i = 0; i < YEARS; i++)
		for (size_t j = 0; j < MONTH_SIZE; j++)
		yearSales += monthSales[i][j];

	cout << "Year sales: " << yearSales << endl;

	return 0;
}