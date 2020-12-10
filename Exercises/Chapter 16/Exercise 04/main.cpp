/*
4. Write a function with an old-style interface that has this prototype:
int reduce(long ar[], int n);

The actual arguments should be the name of an array and the number of elements
in the array.The function should sort an array, remove duplicate values, and return a
value equal to the number of elements in the reduced array.Write the function
using STL functions. (If you decide to use the general unique() function, note that
it returns the end of the resulting range.) Test the function in a short program.
*/

#include <iostream>
#include <algorithm>

int reduce(long ar[], int n);

int main()
{
	int size = 10;
	long ar[] = { 1, 10, 2, 9, 3, 8, 4, 4, 9, 1 };

	for (int i = 0; i < size; i++)
		std::cout << ar[i] << " ";
	std::cout << std::endl;

	size = reduce(ar, size);

	for (int i = 0; i < size; i++)
		std::cout << ar[i] << " ";
	std::cout << std::endl;

	return 0;
}

int reduce(long ar[], int n)
{
	std::sort(ar, ar + n);
	return std::unique(ar, ar + n) - ar;
}