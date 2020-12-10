/*
3. Rewrite the Stock class, as described in Listings 10.7 and 10.8 in Chapter 10 so
that it uses dynamically allocated memory directly instead of using string class
objects to hold the stock names.Also replace the show() member function with an
overloaded operator<<() definition.Test the new definition program in Listing
10.9.
*/

#include <iostream>

#include "stock20.h"

const int STKS = 4;

int main()
{
	// create an array of initialized objects
	Stock stocks[STKS] =
	{
		Stock("NanoSmart", 12, 20.0),
		Stock("Boffo Objects", 200, 2.0),
		Stock("NanoSmart", 130, 3.25),
		Stock("NanoSmart", 60, 6.5),
	};

	std::cout << "Stock holdings:\n";
	int st;
	for (st = 0; st < STKS; st++)
		std::cout << stocks[st];

	// set pointer to first element
	const Stock* top = &stocks[0];
	for (st = 1; st < STKS; st++)
		top = &top->topval(stocks[st]);

	// now top points to the most valuable holding
	std::cout << "\nMost valuable holding:\n";
	std::cout << (*top);

	return 0;
}