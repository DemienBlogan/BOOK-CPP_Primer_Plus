/*
4. Write a program that opens two text files for input and one for output.The program
should concatenate the corresponding lines of the input files, use a space as a
separator, and write the results to the output file. If one file is shorter than the other,
the remaining lines in the longer file should also be copied to the output file. For
example, suppose the first input file has these contents:

eggs kites donuts
balloons hammers
stones

And suppose the second input file has these contents:

zero lassitude
finance drama

The resulting file would have these contents:

eggs kites donuts zero lassitude
balloons hammers finance drama
stones
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
	std::string inputFilename1{ "InputFile1.txt" };
	std::string inputFilename2{ "InputFile2.txt" };

	std::ifstream inputFile1{ inputFilename1 };
	std::ifstream inputFile2{ inputFilename2 };

	if (!inputFile1.is_open())
	{
		std::cerr << "Cannot open file '" << inputFilename1 << "'\n";
		return 2;
	}

	if (!inputFile2.is_open())
	{
		std::cerr << "Cannot open file '" << inputFilename2 << "'\n";
		return 3;
	}

	size_t file1LinesCount = 0, file2LinesCount = 0;
	std::vector<std::string> file1Lines, file2Lines;
	std::string line;

	while (std::getline(inputFile1, line))
	{
		file1Lines.push_back(line);
		file1LinesCount++;
	}

	while (std::getline(inputFile2, line))
	{
		file2Lines.push_back(line);
		file2LinesCount++;
	}

	std::string outputFilename{ "OutputFile.txt" };
	std::ofstream outputFile{ outputFilename };

	size_t i = 0, j = 0;
	for (; i < file1Lines.size() && j < file2Lines.size(); i++, j++)
		outputFile << file1Lines[i] << " " << file2Lines[j] << std::endl;

	for (; i < file1Lines.size(); i++)
		outputFile << file1Lines[i] << std::endl;

	for (; j < file2Lines.size(); j++)
		outputFile << file1Lines[j] << std::endl;

	inputFile1.close();
	inputFile2.close();
	outputFile.close();

	std::cout << "Information is copied.\n";

	return 0;
}