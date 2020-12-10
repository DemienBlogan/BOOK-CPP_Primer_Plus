/*
1. Write a function that normally takes one argument, the address of a string, and
prints that string once. However, if a second, type int, argument is provided and is
nonzero, the function should print the string a number of times equal to the number
of times that function has been called at that point. (Note that the number of
times the string is printed is not equal to the value of the second argument; it is
equal to the number of times the function has been called.) Yes, this is a silly function,
but it makes you use some of the techniques discussed in this chapter. Use the
function in a simple program that demonstrates how the function works.
*/

#include <iostream>

using namespace std;

void Show(const char* str, int times = 0);

int main()
{
	cout << "Call #1:\n";
	Show("Hello World");

	cout << "Call #2:\n";
	Show("Hello World");

	cout << "Call #3:\n";
	Show("Hello World", 2);

	cout << "Call #4:\n";
	Show("Hello World", 3);

	return 0;
}

void Show(const char* str, int times)
{
	static int callCount = 0;
	callCount++;

	if (times == 0)
		cout << str << endl;
	else
		for (int i = 0; i < callCount; i++)
			cout << str << endl;
}