/*
2. Write a program that asks the user to enter up to 10 golf scores, which are to be
stored in an array.You should provide a means for the user to terminate input prior
to entering 10 scores.The program should display all the scores on one line and
report the average score. Handle input, display, and the average calculation with
three separate array-processing functions.
*/

#include <iostream>

using namespace std;

size_t Initialize(double golfScores[], size_t maxSize);
void Show(const double golfScores[], size_t size);
double CalculateAverage(const double golfScores[], size_t size);

int main()
{
	const size_t MAX_SIZE = 10;
	double golfScores[MAX_SIZE];

	size_t size = Initialize(golfScores, MAX_SIZE);

	Show(golfScores, size);

	double average = CalculateAverage(golfScores, size);
	cout << "Average = " << average << endl;

	return 0;
}

size_t Initialize(double golfScores[], size_t maxSize)
{
	size_t size = 0;
	double score;

	for (size_t i = 0; i < maxSize; i++)
	{
		cout << "Enter golf score #" << i + 1 << " (or negative to stop): ";
		cin >> score;

		if (score < 0)
			break;

		size++;
		golfScores[i] = score;
	}

	return size;
}

void Show(const double golfScores[], size_t size)
{
	cout << "Golf Scores: ";
	for (size_t i = 0; i < size; i++)
		cout << golfScores[i] << " ";
	cout << endl;
}

double CalculateAverage(const double golfScores[], size_t size)
{
	double sum = 0.0;

	for (size_t i = 0; i < size; i++)
		sum += golfScores[i];

	double average = sum / size;

	return average;
}