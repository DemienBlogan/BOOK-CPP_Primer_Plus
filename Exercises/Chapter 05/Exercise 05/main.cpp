/*
5. You sell the book C++ for Fools.Write a program that has you enter a year’s worth
of monthly sales (in terms of number of books, not of money).The program should
use a loop to prompt you by month, using an array of char * (or an array of
string objects, if you prefer) initialized to the month strings and storing the input
data in an array of int.Then, the program should find the sum of the array contents
and report the total sales for the year.
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

	int monthSales[MONTH_SIZE];

	for (size_t i = 0; i < MONTH_SIZE; i++)
	{
		cout << "Enter amount of sales in " << MONTHS[i] << ": ";
		cin >> monthSales[i];
	}

	int yearSales = 0;
	for (size_t i = 0; i < MONTH_SIZE; i++)
		yearSales += monthSales[i];

	cout << "Year sales: " << yearSales << endl;

	return 0;
}