/*
2. Modify the Vector class header and implementation files (Listings 11.13 and 11.14)
so that the magnitude and angle are no longer stored as data components. Instead,
they should be calculated on demand when the magval() and angval() methods
are called.You should leave the public interface unchanged (the same public methods
with the same arguments) but alter the private section, including some of the
private method and the method implementations.Test the modified version with
Listing 11.15, which should be left unchanged because the public interface of the
Vector class is unchanged.
*/

#include <iostream>
#include <cstdlib> // rand(), srand() prototypes
#include <ctime>   // time() prototype

#include "vect.h"

int main()
{
	using namespace std;
	using VECTOR::Vector;

	srand(time(0)); // seed random-number generator

	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "Enter target distance(q to quit) : ";
	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;

		cout << "Enter amount of trials: ";
		int trials;
		cin >> trials;

		double highestStepAmount = 0;
		double lowestStepAmount = 0;
		double averageStepAmount = 0;
		double sumStepAmount = 0;

		for (int i = 0; i < trials; i++)
		{
			while (result.magval() < target)
			{
				direction = rand() % 360;
				step.reset(dstep, direction, Vector::POL);
				result = result + step;
				steps++;
			}

			if (i == 0)
				highestStepAmount = lowestStepAmount = steps;
			else
			{
				if (highestStepAmount < steps)
					highestStepAmount = steps;
				if (lowestStepAmount > steps)
					lowestStepAmount = steps;
			}

			sumStepAmount += steps;
			steps = 0;
			result.reset(0.0, 0.0);
		}

		averageStepAmount = sumStepAmount / trials;

		cout << "Highest number of steps = " << highestStepAmount << endl;
		cout << "Lowest number of steps = " << lowestStepAmount << endl;
		cout << "Average number of steps = " << averageStepAmount << endl;

		cout << "Enter target distance (q to quit): ";
	}

	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	return 0;
}