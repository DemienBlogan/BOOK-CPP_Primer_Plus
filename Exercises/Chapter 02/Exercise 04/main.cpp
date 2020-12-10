/*
4. Write a program that asks the user to enter his or her age. The program then should
display the age in months:

Enter your age: 29
Your age in months is 384.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter your age: ";
	int age;
	cin >> age;

	int months = age * 12;

	cout << "Your age in months is " << months << endl;

	return 0;
}