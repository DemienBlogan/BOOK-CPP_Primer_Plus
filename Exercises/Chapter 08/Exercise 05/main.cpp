/*
5. Write a template function max5() that takes as its argument an array of five items
of type T and returns the largest item in the array. (Because the size is fixed, it can
be hard-coded into the loop instead of being passed as an argument.) Test it in a
program that uses the function with an array of five int value and an array of five
double values.
*/

#include <iostream>

using namespace std;

template <typename T>
T max5(const T arr[]);

int main()
{
	int arr1[] = { 10, 50, 5, 30, 20 };
	double arr2[] = { 1.23, 53.5, 12.7, 19.9, 32.1 };

	int max1 = max5(arr1);
	double max2 = max5(arr2);

	cout << "Max1 = " << max1 << endl;
	cout << "Max2 = " << max2 << endl;

	return 0;
}

template <typename T>
T max5(const T arr[])
{
	T max = arr[0];

	for (size_t i = 1; i < 5; i++)
		if (max < arr[i])
			max = arr[i];

	return max;
}