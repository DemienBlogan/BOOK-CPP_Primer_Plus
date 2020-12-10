/*
3. Write a program that asks the user to type in numbers.After each entry, the program
should report the cumulative sum of the entries to date.The program should
terminate when the user enters 0.
*/

#include <iostream>

int main()
{
	using namespace std;

	int number;
	int sum = 0;

	do
	{
		cout << "Enter a number (or 0 to stop): ";
		cin >> number;
		sum += number;

	} while (number != 0);

	cout << "Sum = " << sum << endl;

	return 0;
}