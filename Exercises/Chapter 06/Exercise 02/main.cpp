/*
2. Write a program that reads up to 10 donation values into an array of double. (Or, if
you prefer, use an array template object.) The program should terminate input on
non-numeric input. It should report the average of the numbers and also report
how many numbers in the array are larger than the average.
*/

#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<double, 10> numbers;

	cout << "Enter 10 numbers (or q to stop):\n";
	int size = 0;

	cout << "Value #1: ";
	cin >> numbers[size++];

	while (size < 10 && cin)
	{
		cout << "Value #" << size + 1 << ": ";
		cin >> numbers[size++];
	}

	if (size == 1)
		cout << "There is no values.\n";
	else
	{
		double sum = 0;

		for (size_t i = 0; i < size; i++)
			sum += numbers[i];

		double average = sum / size;

		cout << "Average = " << average << endl;

		int greaterThanAverage = 0;
		for (size_t i = 0; i < size; i++)
			if (numbers[i] > average)
				greaterThanAverage++;

		cout << "There is " << greaterThanAverage << " values greater than average.\n";
	}

	return 0;
}