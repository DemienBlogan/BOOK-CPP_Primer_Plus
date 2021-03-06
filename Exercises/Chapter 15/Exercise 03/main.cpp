/*
3. This exercise is the same as Programming Exercise 2, except that the exceptions
should be derived from a base class (itself derived from logic_error) that stores the
two argument values, the exceptions should have a method that reports these values
as well as the function name, and a single catch block that catches the base-class
exemption should be used for both exceptions, with either exception causing the
loop to terminate.
*/ 

#include <iostream>
#include <stdexcept>
#include <cmath>

class bad_mean : public std::logic_error
{
public:
	bad_mean() = default;
	bad_mean(const char* message)
		: std::logic_error(message)
	{ }

	virtual const char* what() const override
	{
		return std::logic_error::what();
	}
};

class bad_hmean : public bad_mean
{
public:
	bad_hmean() = default;
	bad_hmean(const char* message)
		: bad_mean(message)
	{ }
};

class bad_gmean : public bad_mean
{
public:
	bad_gmean() = default;
	bad_gmean(const char* message)
		: bad_mean(message)
	{ }
};

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
		catch (bad_mean& bg)
		{
			cout << bg.what() << endl;
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