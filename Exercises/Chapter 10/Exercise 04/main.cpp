/*
4. Do Programming Exercise 4 from Chapter 9 but convert the Sales structure and
its associated functions to a class and its methods. Replace the setSales(Sales &,
double [], int) function with a constructor. Implement the interactive
setSales(Sales &) method by using the constructor. Keep the class within the
namespace SALES.
*/

#include "Sales.h"

using namespace SALES;

int main()
{
	const size_t SIZE2 = 4;
	double arr[SIZE2] = { 1, 2, 3, 4 };

	const size_t SIZE = 2;
	SALES::Sales sales[SIZE] =
	{
		Sales(arr, SIZE2),
		Sales()
	};

	for (size_t i = 0; i < SIZE; i++)
		sales[i].Show();

	return 0;
}