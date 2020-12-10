/*
3. Write a program that copies one file to another. Have the program take the filenames
from the command line. Have the program report if it cannot open a file.
*/

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cerr << "Incorrect count of main arguments.\n";
		return 1;
	}

	std::ifstream fin{ argv[1] };
	std::ofstream fout{ argv[2] };

	if (!fin.is_open())
	{
		std::cerr << "Cannot open file '" << argv[1] << "'\n";
		return 2;
	}

	if (!fout.is_open())
	{
		std::cerr << "Cannot open/create file '" << argv[2] << "'\n";
		return 3;
	}

	char ch;
	while (fin.get(ch))
		fout.put(ch);

	fin.close();
	fout.close();

	std::cout << "Information is copied.\n";

	return 0;
}