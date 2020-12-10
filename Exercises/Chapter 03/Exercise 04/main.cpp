/*
4. Write a program that asks the user to enter the number of seconds as an integer
value (use type long, or, if available, long long) and that then displays the equivalent
time in days, hours, minutes, and seconds. Use symbolic constants to represent
the number of hours in the day, the number of minutes in an hour, and the number
of seconds in a minute.The output should look like this:

Enter the number of seconds: 31600000
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter the number of seconds: ";
	long long totalSeconds;
	cin >> totalSeconds;

	int copySeconds = totalSeconds;

	const int SEC_IN_MIN = 60, MIN_IN_HOUR = 60, HOURS_IN_DAY = 24;
	const int SEC_IN_HOUR = SEC_IN_MIN * MIN_IN_HOUR;
	const int SEC_IN_DAY = SEC_IN_HOUR * HOURS_IN_DAY;

	int days = totalSeconds / SEC_IN_DAY;
	totalSeconds = totalSeconds % SEC_IN_DAY;

	int hours = totalSeconds / SEC_IN_HOUR;
	totalSeconds = totalSeconds % SEC_IN_HOUR;

	int minutes = totalSeconds / SEC_IN_MIN;
	totalSeconds = totalSeconds % SEC_IN_MIN;

	int seconds = totalSeconds;

	cout << copySeconds << " seconds = " << days << " days, " << hours << " hours, ";
	cout << minutes << " minutes, " << seconds << " seconds\n";

	return 0;
}