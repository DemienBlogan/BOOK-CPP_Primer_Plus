/*
7. Write a program that asks you to enter an automobile gasoline consumption figure
in the European style (liters per 100 kilometers) and converts to the U.S. style of
miles per gallon. Note that in addition to using different units of measurement, the
U.S. approach (distance / fuel) is the inverse of the European approach (fuel / distance).
Note that 100 kilometers is 62.14 miles, and 1 gallon is 3.875 liters. Thus, 19
mpg is about 12.4 l/100 km, and 27 mpg is about 8.7 l/100 km.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter gasoline consumption (liters per 100 kilometers): ";
	double litresPer100Kilometers;
	cin >> litresPer100Kilometers;

	const double LITERS_IN_GALLON = 3.875;
	double gallonsPer100Kilometes = litresPer100Kilometers / LITERS_IN_GALLON;

	const double KILOMETERS_IN_MILES = 1.609;
	double gallonsPer100Miles = gallonsPer100Kilometes * KILOMETERS_IN_MILES;
	double milesPerGallon = 100.0 / gallonsPer100Miles;

	cout << litresPer100Kilometers << " litres / 100 kilometers = ";
	cout << milesPerGallon << " miles / 1 gallon.\n";

	return 0;
}