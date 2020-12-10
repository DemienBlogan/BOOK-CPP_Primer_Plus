/*
5. Do the same problem as described in Programming Exercise 4, except make it a
template function:
template <class T>
int reduce(T ar[], int n);

Test the function in a short program, using both a long instantiation and a string
instantiation.
*/

#include <iostream>
#include <algorithm>
#include <string>

template <class T>
int reduce(T ar[], int n);

template <typename T>
void Show(const T arr[], int size);

int main()
{
	int size = 10;
	long ar[] = { 1, 10, 2, 9, 3, 8, 4, 4, 9, 1 };

	Show(ar, size);

	size = reduce(ar, size);

	Show(ar, size);

	size = 10;

	std::string ar2[] = { "w", "q", "d", "a", "d", "b", "o", "l", "l", "w" };

	Show(ar2, size);

	size = reduce(ar2, size);

	Show(ar2, size);

	return 0;
}

template <class T>
int reduce(T ar[], int n)
{
	std::sort(ar, ar + n);
	return std::unique(ar, ar + n) - ar;
}

template <typename T>
void Show(const T arr[], int size)
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}