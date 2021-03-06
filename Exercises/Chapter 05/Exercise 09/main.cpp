/*
9. Write a program that matches the description of the program in Programming
Exercise 8, but use a string class object instead of an array. Include the string
header file and use a relational operator to make the comparison test.
*/

#include <iostream>
#include <string>

int main()
{
	using namespace std;

	string word;
	int totalWords = 0;

	cout << "Enter words (to stop, type the word done):\n";
	cin >> word;
	while (word != "done")
	{
		totalWords++;
		cin >> word;
	}

	cout << "You entered a total of " << totalWords << " words.\n";

	return 0;
}