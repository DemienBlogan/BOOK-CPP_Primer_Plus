/*
3. Do Programming Exercise 1 from Chapter 9 but replace the code shown there with
an appropriate golf class declaration. Replace setgolf(golf &, const char*,
int) with a constructor with the appropriate argument for providing initial values.
Retain the interactive version of setgolf() but implement it by using the constructor.
(For example, for the code for setgolf(), obtain the data, pass the data to
the constructor to create a temporary object, and assign the temporary object to the
invoking object, which is *this.)
*/

#include <iostream>

#include "golf.h"

using std::cout;

int main()
{
	const size_t SIZE = 3;

	Golf players[SIZE] =
	{
		Golf("Demien Blogan", 1.3),
		Golf("Anya Cickalishin", 2.6),
		Golf("Olga Vasilchuk", 3.9)
	};

	cout << "Original array #1:\n";
	for (size_t i = 0; i < SIZE; i++)
		players[i].Show();

	for (size_t i = 0; i < SIZE; i++)
		players[i].SetHandicap(i + i + 1);

	cout << "Original array #1:\n";
	for (size_t i = 0; i < SIZE; i++)
		players[i].Show();

	Golf players2[SIZE];

	cout << "User array #2:\n";
	for (size_t i = 0; i < SIZE; i++)
		players2[i].Show();

	return 0;
}