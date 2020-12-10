/*
8. Write a program that opens a text file, reads it character-by-character to the end of
the file, and reports the number of characters in the file.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream file("File.txt");

	if (!file)
	{
		cout << "File 'File.txt' could not been opened.\n";
		return 1;
	}

	int charCount = 0;

	while (file.get() != EOF)
		charCount++;

	cout << "File has " << charCount << " characters.\n";
	file.close();

	return 0;
}