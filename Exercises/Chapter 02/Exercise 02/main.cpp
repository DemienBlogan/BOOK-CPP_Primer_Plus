/*
2. Write a C++ program that asks for a distance in furlongs and converts it to yards.
(One furlong is 220 yards.)
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the distance in furlongs: ";
	int furlongs;
	cin >> furlongs;

	int yards = furlongs * 220;

	cout << furlongs << " furlongs = " << yards << " yards.\n";

	return 0;
}