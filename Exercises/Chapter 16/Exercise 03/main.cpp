/*
3. Redo Listing 16.3 so that it gets it words from a file. One approach is to use a
vector<string> object instead of an array of string.Then you can use
push_back() to copy how ever many words are in your data file into the
vector<string> object and use the size() member to determine the length of
the word list. Because the program should read one word at a time from the file,
you should use the >> operator rather than getline().The file itself should contain
words separated by spaces, tabs, or new lines.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>

using std::string;

int main()
{
	using std::cout;
	using std::cin;
	using std::tolower;
	using std::endl;

	std::srand(static_cast<unsigned>(std::time(nullptr)));

	std::string wordListFilename{ "WordList.txt" };
	std::ifstream wordListFile{ wordListFilename };
	
	std::vector<std::string> wordList;
	std::string word;

	while (wordListFile >> word)
		wordList.push_back(word);

	char play;
	cout << "Will you play a word game? <y/n> ";
	cin >> play;

	play = tolower(play);

	while (play == 'y')
	{
		string target = wordList[std::rand() % wordList.size()];
		int length = target.length();
		string attempt(length, '-');
		string badchars;
		int guesses = 6;

		cout << "Guess my secret word. It has " << length;
		cout << " letters, and you guess\n";
		cout << "one letter at a time. You get " << guesses;
		cout << " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;

		while (guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;

			if (badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}

			int loc = target.find(letter);

			if (loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter; // add to string
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;

				// check if letter appears again
				loc = target.find(letter, loc + 1);
				while (loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}

			cout << "Your word: " << attempt << endl;
			if (attempt != target)
			{
				if (badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;

				cout << guesses << " bad guesses left\n";
			}
		}

		if (guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";

		cout << "Will you play another? <y/n> ";
		cin >> play;
		play = tolower(play);
	}

	cout << "Bye\n";

	return 0;
}