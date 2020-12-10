/*
6. Write a template function maxn() that takes as its arguments an array of items of
type T and an integer representing the number of elements in the array and that
returns the largest item in the array.Test it in a program that uses the function template
with an array of six int value and an array of four double values.The program
should also include a specialization that takes an array of pointers-to-char as
an argument and the number of pointers as a second argument and that returns the
address of the longest string. If multiple strings are tied for having the longest
length, the function should return the address of the first one tied for longest.Test
the specialization with an array of five string pointers.
*/

#include <iostream>

using namespace std;

template <typename T>
T maxn(const T arr[], size_t size);

template <>
const char* maxn<const char*>(const char* const arr[], size_t size);

int main()
{
	const size_t SIZE1 = 4, SIZE2 = 6, SIZE3 = 5;
	int arr1[SIZE1] = { 10, 50, 5, 30 };
	double arr2[SIZE2] = { 1.23, 53.5, 12.7, 19.9, 32.1, 10.55 };
	const char* arr3[SIZE3] = { "Hi", "Hello", "Hey", "Hayhay", "Huray" };

	int max1 = maxn(arr1, SIZE1);
	double max2 = maxn(arr2, SIZE2);
	const char* max3 = maxn(arr3, SIZE3);

	cout << "Max1 = " << max1 << endl;
	cout << "Max2 = " << max2 << endl;
	cout << "Max3 = " << max3 << endl;

	return 0;
}

template <typename T>
T maxn(const T arr[], size_t size)
{
	T max = arr[0];

	for (size_t i = 1; i < size; i++)
		if (max < arr[i])
			max = arr[i];

	return max;
}

template<>
const char* maxn(const char* const arr[], size_t size)
{
	const char* maxString = arr[0];
	size_t maxLength = strlen(arr[0]);

	for (size_t i = 1; i < size; i++)
	{
		size_t length = strlen(arr[i]);

		if (maxLength < length)
		{
			maxLength = length;
			maxString = arr[i];
		}
	}

	return maxString;
}