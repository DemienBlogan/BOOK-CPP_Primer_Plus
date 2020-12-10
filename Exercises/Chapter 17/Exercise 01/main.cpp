/*
1. Write a program that counts the number of characters up to the first $ in input and
that leaves the $ in the input stream.
*/

#include <iostream>

int main()
{
	std::cout << "Enter characters ($ to stop):\n";

	char ch;

	while (std::cin >> ch && ch != '$')
		continue;

	if (std::cin.good())
		std::cin.putback('$');

	return 0;
}