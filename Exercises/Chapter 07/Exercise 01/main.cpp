/*
1. Write a program that repeatedly asks the user to enter pairs of numbers until at
least one of the pair is 0. For each pair, the program should use a function to calculate
the harmonic mean of the numbers.The function should return the answer to
main(), which should report the result.The harmonic mean of the numbers is the
inverse of the average of the inverses and can be calculated as follows:
harmonic mean = 2.0 × x × y / (x + y)
*/

#include <iostream>

using namespace std;

double CalculateHarmoticMean(double number1, double number2);

int main()
{
	int number1, number2;

	cout << "Enter two numbers (0 to stop): ";
	cin >> number1 >> number2;
	while (number1 != 0 && number2 != 0)
	{
		double harmonicMean = CalculateHarmoticMean(number1, number2);
		cout << "Harmonic Mean = " << harmonicMean << endl;

		cout << "Enter next two numbers (0 to stop): ";
		cin >> number1 >> number2;
	}

	return 0;
}

double CalculateHarmoticMean(double number1, double number2)
{
	double harmonicMean = 2.0 * number1 * number2 / (number1 + number2);
	return harmonicMean;
}