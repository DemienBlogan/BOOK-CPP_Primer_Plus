/*
3. Begin with the following structure declaration:
struct chaff
{
	char dross[20];
	int slag;
};

Write a program that uses placement new to place an array of two such structures in
a buffer.Then assign values to the structure members (remembering to use
strcpy() for the char array) and use a loop to display the contents. Option 1 is to
use a static array, like that in Listing 9.10, for the buffer. Option 2 is to use regular
new to allocate the buffer.
*/

#include <iostream>
#include <new>

using namespace std;

struct chaff
{
	char dross[20];
	int slag;
};

char buffer[256];

int main()
{
	const size_t SIZE = 2;
	chaff* arr = new (buffer) chaff[SIZE]
	{
		{ "Chaff #1", 10 },
		{ "Chaff #2", 20 }
	};

	for (size_t i = 0; i < SIZE; i++)
	{
		cout << arr[i].dross << ": " << arr[i].slag << endl;
	}

	return 0;
}