/*
7. A common game is the lottery card.The card has numbered spots of which a certain
number are selected at random.Write a Lotto() function that takes two arguments.
The first should be the number of spots on a lottery card, and the second
should be the number of spots selected at random.The function should return a
vector<int> object that contains, in sorted order, the numbers selected at random.
For example, you could use the function as follows:
vector<int> winners;
winners = Lotto(51,6);

This would assign to winners a vector that contains six numbers selected randomly
from the range 1 through 51. Note that simply using rand() doesn’t quite do the
job because it may produce duplicate values. Suggestion: Have the function create a
vector that contains all the possible values, use random_shuffle(), and then use the
beginning of the shuffled vector to obtain the values.Also write a short program
that lets you test the function.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

std::vector<int> Lotto(int maxRandNumber, int numbersCount);

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	int maxRandomNumber = 51;
	int numbersCount = 6;

	std::vector<int> winners = Lotto(maxRandomNumber, numbersCount);

	std::cout << "Winners: ";
	for (int winner : winners)
		std::cout << winner << " ";
	std::cout << std::endl;

	return 0;
}

std::vector<int> Lotto(int maxRandNumber, int numbersCount)
{
	std::vector<int> allValues(maxRandNumber);

	for (int i = 0; i < maxRandNumber; i++)
		allValues[i] = i + 1;

	std::random_shuffle(allValues.begin(), allValues.end());

	std::vector<int> winners{ allValues.cbegin(), allValues.cbegin() + numbersCount };
	return winners;
}