/*
2. Modify Listing 15.11 so that the two exception types are classes derived from the
logic_error class provided by the <stdexcept> header file. Have each what()
method report the function name and the nature of the problem.The exception
objects need not hold the bad values; they should just support the what() method.
*/

#include <iostream>
#include <cmath>
#include "exc_mean.h"

// function prototypes
double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double x, y, z;

	cout << "Enter two numbers: ";
	while (cin >> x >> y)
	{
		try
		{
			z = hmean(x, y);

			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;

			cout << "Enter next set of numbers <q to quit>: ";
		}
		catch (bad_hmean& bg)
		{
			cout << bg.what() << endl;
			cout << "Try again.\n";

			continue;
		}
		catch (bad_gmean& hg)
		{
			cout << hg.what() << endl;
			cout << "Sorry, you don't get to play any more.\n";

			break;
		}
	}

	cout << "Bye!\n";

	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean("One or two values are incorrect");

	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean("One or two values are incorrect");

	return std::sqrt(a * b);
}