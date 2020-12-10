/*
10. Write a program that requests the user to enter three times for the 40-yd dash (or
40-meter, if you prefer) and then displays the times and the average. Use an array
object to hold the data. (Use a built-in array if array is not available.)
*/

#include <iostream>
#include <array>
using namespace std;

int main()
{
	array<double, 3> dash;

	for (size_t i = 0; i < dash.size(); i++)
	{
		cout << "Number #" << i + 1 << ": ";
		cin >> dash[i];
	}

	double sum = 0;
	for (size_t i = 0; i < dash.size(); i++)
		sum += dash[i];

	double average = sum / dash.size();

	cout << "Times: ";
	for (size_t i = 0; i < dash.size(); i++)
		cout << dash[i] << " ";
	cout << endl;
	
	cout << "Average = " << average << endl;

	return 0;
}