/*
2. Redo Listing 5.4 using a type array object instead of a built-in array and type
long double instead of long long. Find the value of 100!
*/

#include <iostream>
#include <array>

const int ArSize = 101;

int main()
{
	using namespace std;

	array<long double, ArSize> factorials;

	factorials[1] = factorials[0] = 1.0L;

	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];

	for (int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << std::endl;

	return 0;
}