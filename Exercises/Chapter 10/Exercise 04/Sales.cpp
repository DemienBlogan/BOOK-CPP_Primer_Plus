#include <iostream>

#include "Sales.h"

using std::cout;
using std::cin;
using std::endl;

SALES::Sales::Sales()
{
	cout << "Input sales:\n";
	for (size_t i = 0; i < QUARTERS; i++)
	{
		cout << "Quarter #" << i + 1 << ": ";
		cin >> sales[i];
	}

	double sum = 0;
	max = min = sales[0];

	for (int i = 0; i < QUARTERS; i++)
	{
		sum += sales[i];

		if (max < sales[i])
			max = sales[i];

		if (min > sales[i])
			min = sales[i];
	}

	average = sum / QUARTERS;
}

SALES::Sales::Sales(const double ar[], int n)
{
	double sum = 0;
	max = min = ar[0];

	for (int i = 0; i < n; i++)
	{
		sales[i] = ar[i];

		sum += sales[i];

		if (max < sales[i])
			max = sales[i];

		if (min > sales[i])
			min = sales[i];
	}

	average = sum / QUARTERS;
}

void SALES::Sales::Show() const
{
	cout << "Sales: ";
	for (size_t i = 0; i < QUARTERS; i++)
		cout << sales[i] << " ";

	cout << "\nMax = " << max << endl;
	cout << "Min = " << min << endl;
	cout << "Average = " << average << endl;
}