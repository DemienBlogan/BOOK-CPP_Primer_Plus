/*
1. Write a program that reads keyboard input to the @ symbol and that echoes the
input except for digits, converting each uppercase character to lowercase, and vice
versa. (Don’t forget the cctype family.)
*/

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
	char ch;

	cout << "Enter characters (or @ to stop): ";

	cin.get(ch);
	while (ch != '@')
	{
		if (isdigit(ch))
		{
			cin.get(ch);
			continue;
		}

		if (iswupper(ch))
			ch = tolower(ch);

		cout << ch;

		cin.get(ch);
	}

	return 0;
}