/*
6. Write a program that uses the following functions:
Fill_array() takes as arguments the name of an array of double values and an
array size. It prompts the user to enter double values to be entered in the array. It
ceases taking input when the array is full or when the user enters non-numeric
input, and it returns the actual number of entries.

Show_array() takes as arguments the name of an array of double values and an
array size and displays the contents of the array.

Reverse_array() takes as arguments the name of an array of double values and an
array size and reverses the order of the values stored in the array.
The program should use these functions to fill an array, show the array, reverse the
array, show the array, reverse all but the first and last elements of the array, and then
show the array.
*/

#include <iostream>

using namespace std;

size_t Fill_array(double arr[], size_t maxSize);
void Show_array(const double arr[], size_t size);
void Reverse_array(double arr[], size_t size);

int main()
{
	const size_t MAX_SIZE = 10;
	double arr[MAX_SIZE];

	size_t size = Fill_array(arr, MAX_SIZE);

	cout << "Origin array: ";
	Show_array(arr, size);

	Reverse_array(arr, size);

	cout << "Reversed array: ";
	Show_array(arr, size);

	return 0;
}

size_t Fill_array(double arr[], size_t maxSize)
{
	size_t size = 0;
	double number;

	for (size_t i = 0; i < maxSize; i++)
	{
		cout << "Enter arr[" << i << "] (or q to stop): ";
		cin >> number;

		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			break;
		}

		size++;
		arr[i] = number;
	}

	return size;
}

void Show_array(const double arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void Reverse_array(double arr[], size_t size)
{
	for (size_t i = 1, j = size - 2; i < j; i++, j--)
		swap(arr[i], arr[j--]);
}