/*
3. Write a precursor to a menu-driven program.The program should display a menu
offering four choices, each labeled with a letter. If the user responds with a letter
other than one of the four valid choices, the program should prompt the user to
enter a valid response until the user complies.Then the program should use a
switch to select a simple action based on the user’s selection.A program run could
look something like this:

Please enter one of the following choices:
c) carnivore p) pianist
t) tree g) game
f
Please enter a c, p, t, or g: q
Please enter a c, p, t, or g: t
A maple is a tree.
*/

#include <iostream>

using namespace std;

int main()
{
	char menuItem;

	do
	{
		cout << "Please enter one of the following choices:\n";
		cout << "o) Olga                s) Sonya           \n";
		cout << "a) Anya                t) Tanya           \n";
		cout << "q) Quit                                   \n";

		cin >> menuItem;

		while (cin.get() != '\n')
			continue;

		switch (menuItem)
		{
		case 'o':
		case 'O':
			cout << "She's the most beautiful girl I've ever seen.\n";
			cout << "Sometimes I miss her.\n";
			break;

		case 's':
		case 'S':
			cout << "She's the yongest girl I have fallen in love with.\n";
			cout << "It's very shame that I'm not a type of guys she was\n";
			cout << "interested in.\n";
			break;

		case 'a':
		case 'A':
			cout << "This girl was very close to me. We almost started\n";
			cout << "relationships. But she was from other city, so that's\n";
			cout << "not my case, I thought.\n";
			break;

		case 't':
		case 'T':
			cout << "She gave me the best day of my life. She was so stupid for me,\n";
			cout << "but she was very cute and very kind to me. Thank you, Tanya.\n";
			cout << "Thanks for that day. The only one.\n";
			break;

		case 'q':
		case 'Q':
			cout << "Find peace, programmer. Find yourself and the person who you\n";
			cout << "will want to give your heart. But be careful. Peace, mate...\n";
			break;

		default:
			cout << "Incorrect input. Try again.\n";
			break;
		}

	} while (menuItem != 'q' && menuItem != 'Q');

	return 0;
}