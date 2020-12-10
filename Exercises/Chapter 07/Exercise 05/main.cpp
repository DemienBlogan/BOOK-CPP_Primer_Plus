/*
5. Define a recursive function that takes an integer argument and returns the factorial
of that argument. Recall that 3 factorial, written 3!, equals 3 × 2!, and so on, with 0!
defined as 1. In general, if n is greater than zero, n! = n * (n - 1)!.Test your function
in a program that uses a loop to allow the user to enter various values for which the
program reports the factorial.
*/

#include <iostream>

using namespace std;

unsigned long long Factorial(int number);

int main()
{
	int number;
	unsigned long long factorial;

	do
	{
		cout << "Enter a number: ";
		cin >> number;

		if (number >= 0)
		{
			factorial = Factorial(number);
			cout << number << "! = " << factorial << endl;
		}

	} while (number >= 0);

	return 0;
}

unsigned long long Factorial(int number)
{
	return number <= 1 ? 1 : number * Factorial(number - 1);
}