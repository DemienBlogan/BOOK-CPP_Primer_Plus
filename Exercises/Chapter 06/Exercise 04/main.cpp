/*
4. When you join the Benevolent Order of Programmers, you can be known at BOP
meetings by your real name, your job title, or your secret BOP name.Write a program
that can list members by real name, by job title, by secret name, or by a member’s
preference. Base the program on the following structure:
// Benevolent Order of Programmers name structure
struct bop 
{
char fullname[strsize]; // real name
char title[strsize];    // job title
char bopname[strsize];  // secret BOP name
int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

In the program, create a small array of such structures and initialize it to suitable
values. Have the program run a loop that lets the user select from different alternatives:

a. display by name b. display by title
c. display by bopname d. display by preference
q. quit

Note that “display by preference” does not mean display the preference member; it
means display the member corresponding to the preference number. For instance, if
preference is 1, choice d would display the programmer’s job title.A sample run
may look something like the following:

Benevolent Order of Programmers Report
a. display by name b. display by title
c. display by bopname d. display by preference
q. quit

Enter your choice: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand
Next choice: d
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY
Next choice: q
Bye!
*/

#include <iostream>

using namespace std;

struct bop
{
	char fullname[40];
	char title[40];
	char bopname[40];
	int preference; // 0 = fullname, 1 = title, 2 = bopname
};

int main()
{
	char menuItem;
	const size_t PEOPLE = 4;
	bop list[PEOPLE] =
	{
		{ "Demien Blogan", "Team Lead", "BuLL", 3 },
		{ "Olga Vasilchuk" , "Senior Designer", "GG", 1 },
		{ "Vita Vasilchuk" , "Middle Artist", "Killem", 2 },
		{ "Sonya Fedorchuk" , "Junior Tester", "lil'bitch", 3 },
	};

	do
	{
		cout << "Benevolent Order of Programmers Report          \n";
		cout << "a. display by name     b. display by title      \n";
		cout << "c. display by bopname  d. display by preference \n";
		cout << "q. quit                                         \n";

		cin >> menuItem;

		while (cin.get() != '\n')
			continue;

		switch (menuItem)
		{
		case 'a':
		case 'A':
			for (size_t i = 0; i < PEOPLE; i++)
				cout << "Person #" << i + 1 << ": " << list[i].fullname << endl;
			cout << endl;
			break;

		case 'b':
		case 'B':
			for (size_t i = 0; i < PEOPLE; i++)
				cout << "Person #" << i + 1 << ": " << list[i].title << endl;
			cout << endl;
			break;

		case 'c':
		case 'C':
			for (size_t i = 0; i < PEOPLE; i++)
				cout << "Person #" << i + 1 << ": " << list[i].bopname << endl;
			cout << endl;
			break;

		case 'd':
		case 'D':
			for (size_t i = 0; i < PEOPLE; i++)
			{
				switch (list[i].preference)
				{
				case 1:
					cout << "Person #" << i + 1 << ": " << list[i].fullname << endl;
					break;

				case 2:
					cout << "Person #" << i + 1 << ": " << list[i].title << endl;
					break;

				case 3:
					cout << "Person #" << i + 1 << ": " << list[i].bopname << endl;
					break;

				default:
					cout << "Error. Incorrect preference.\n";
					break;
				}
			}
			cout << endl;
			break;

		case 'q':
		case 'Q':
			cout << "Bye!\n";
			break;

		default:
			cout << "Incorrect input. Try again.\n";
			break;
		}

	} while (menuItem != 'q' && menuItem != 'Q');

	return 0;
}