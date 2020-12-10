/*
6. Rewrite the Stonewt class (Listings 11.16 and 11.17) so that it overloads all six
relational operators.The operators should compare the pounds members and return
a type bool value.Write a program that declares an array of six Stonewt objects and
initializes the first three objects in the array declaration.Then it should use a loop
to read in values used to set the remaining three array elements.Then it should
report the smallest element, the largest element, and how many elements are greater
or equal to 11 stone. (The simplest approach is to create a Stonewt object initialized
to 11 stone and to compare the other objects with that object.)
*/

#include <iostream>

#include "stonewh.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const size_t SIZE = 6;
	Stonewt arr[SIZE] =
	{
		Stonewt(10.5),
		Stonewt(13.6),
		Stonewt(15.7)
	};

	for (size_t i = 3; i < SIZE; i++)
	{
		cout << "Enter pounds for arr[" << i << "]: ";
		double pounds;
		cin >> pounds;

		arr[i] = Stonewt(pounds);
	}

	double min = arr[0].GetPounds();
	double max = arr[0].GetPounds();
	int greaterOrEqual11Stone = 0;

	for (size_t i = 1; i < SIZE; i++)
	{
		if (max < arr[i].GetPounds())
			max = arr[i].GetPounds();

		if (min > arr[i].GetPounds())
			min = arr[i].GetPounds();

		if (arr[i] > Stonewt(11, 0))
			greaterOrEqual11Stone++;
	}

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << "Value #" << i + 1 << ": ";
		cout << arr[i] << endl;
	}

	cout << "Max value = " << max << endl;
	cout << "Min value = " << min << endl;
	cout << "Greater than 11 value = " << greaterOrEqual11Stone << endl;

	return 0;
}