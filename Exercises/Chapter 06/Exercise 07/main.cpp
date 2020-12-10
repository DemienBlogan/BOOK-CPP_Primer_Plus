/*
7. Write a program that reads input a word at a time until a lone q is entered.The
program should then report the number of words that began with vowels, the number
that began with consonants, and the number that fit neither of those categories.
One approach is to use isalpha() to discriminate between words beginning with
letters and those that don’t and then use an if or switch statement to further identify
those passing the isalpha() test that begin with vowels.A sample run might
look like this:

Enter words (q to quit):
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 others
*/

#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main()
{
	int vowels = 0, consonants = 0, others = 0;
	char word[30];

	cout << "Enter words (q to quit): ";
	cin >> word;

	while (strcmp(word, "q"))
	{
		if (isalpha(word[0]))
		{
			switch (word[0])
			{
			case 'A': case 'a':
			case 'E': case 'e':
			case 'I': case 'i':
			case 'O': case 'o':
			case 'U': case 'u':
				vowels++;
				break;
			default:
				consonants++;
				break;
			}
		}
		else
			others++;

		cin >> word;
	}

	cout << vowels << " words beginning with vowels\n";
	cout << consonants << " words beginning with consonants\n";
	cout << others << " others\n";

	return 0;
}