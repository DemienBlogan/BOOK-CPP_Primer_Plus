/*
3. Write a program that asks the user to enter a latitude in degrees, minutes, and seconds
and that then displays the latitude in decimal format.There are 60 seconds of
arc to a minute and 60 minutes of arc to a degree; represent these values with symbolic
constants.You should use a separate variable for each input value.A sample
run should look like this:

Enter a latitude in degrees, minutes, and seconds:
First, enter the degrees: 37
Next, enter the minutes of arc: 51
Finally, enter the seconds of arc: 19
37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter a latitude in degrees, minutes, and seconds:\n";
	cout << "First, enter the degrees: ";
	int degrees;
	cin >> degrees;

	cout << "Next, enter the minutes of arc: ";
	double minutes;
	cin >> minutes;

	cout << "Finally, enter the seconds of arc: ";
	double seconds;
	cin >> seconds;

	const int SEC_IN_MIN = 60, MIN_IN_DEG = 60;
	double total = degrees + (minutes / MIN_IN_DEG) + (seconds / SEC_IN_MIN / MIN_IN_DEG);
	
	cout << degrees << " degrees, " << minutes << " minutes, " << seconds << " seconds = ";
	cout << total << " degrees\n";

	return 0;
}