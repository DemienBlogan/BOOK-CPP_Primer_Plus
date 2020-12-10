#include <iostream>

#include "Sales.h"

using namespace std;

void SALES::setSales(Sales& s, const double ar[], int n)
{
	double sum = 0;
	s.max = s.min = ar[0];

	for (int i = 0; i < n; i++)
	{
		s.sales[i] = ar[i];
		
		sum += s.sales[i];

		if (s.max < s.sales[i])
			s.max = s.sales[i];

		if (s.min > s.sales[i])
			s.min = s.sales[i];
	}

	s.average = sum / QUARTERS;
}

void SALES::setSales(Sales& s)
{
	cout << "Input sales:\n";
	for (size_t i = 0; i < QUARTERS; i++)
	{
		cout << "Quarter #" << i + 1 << ": ";
		cin >> s.sales[i];
	}

	double sum = 0;
	s.max = s.min = s.sales[0];

	for (int i = 0; i < QUARTERS; i++)
	{
		sum += s.sales[i];

		if (s.max < s.sales[i])
			s.max = s.sales[i];

		if (s.min > s.sales[i])
			s.min = s.sales[i];
	}

	s.average = sum / QUARTERS;
}

void SALES::showSales(const Sales& s)
{
	cout << "Sales: ";
	for (size_t i = 0; i < QUARTERS; i++)
	{
		cout << s.sales[i] << " ";
	}
	cout << "\nMax = " << s.max << endl;
	cout << "Min = " << s.min << endl;
	cout << "Average = " << s.average << endl;
}