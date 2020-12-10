/*
2. Write a program that copies your keyboard input (up to the simulated end-of-file)
to a file named on the command line.
*/

#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cerr << "Incorrect count of main arguments.\n";
		return 1;
	}

	std::ofstream fout{ argv[1] };

	if (!fout.is_open())
	{
		std::cerr << "Cannot open/create file '" << argv[1] << "'\n";
		return 2;
	}

	std::cout << "Enter characters (Ctrl+Z to stop):\n";
	char ch;

	while (std::cin.get(ch))
		fout.put(ch);

	fout.close();

	std::cout << "Information is wroten.\n";

	return 0;
}