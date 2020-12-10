/*
3. Modify Listing 11.15 so that instead of reporting the results of a single trial for a
particular target/step combination, it reports the highest, lowest, and average number
of steps for N trials, where N is an integer entered by the user.
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