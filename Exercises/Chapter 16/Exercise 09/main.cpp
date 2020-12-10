/*
9. Compared to an array, a linked list features easier addition and removal of elements
but is slower to sort.This raises a possibility: Perhaps it might be faster to copy a list
to an array, sort the array, and copy the sorted result back to the list than to simply
use the list algorithm for sorting. (But it also could use more memory.) Test the
speed hypothesis with the following approach:

a. Create a large vector<int> object vi0, using rand() to provide initial
values.

b. Create a second vector<int> object vi and a list<int> object li of the
same size as the original and initialize them to values in the original vector.

c. Time how long the program takes to sort vi using the STL sort() algorithm,
then time how long it takes to sort li using the list sort() method.

d. Reset li to the unsorted contents of vi0.Time the combined operation of
copying li to vi, sorting vi, and copying the result back to li.

To time these operations, you can use clock() from the ctime library. As in Listing
5.14, you can use this statement to start the first timing:
clock_t start = clock();

Then use the following at the end of the operation to get the elapsed time:
clock_t end = clock();
cout << (double)(end - start)/CLOCKS_PER_SEC;

This is by no means a definitive test because the results will depend on a variety of
factors, including available memory, whether multiprocessing is going on, and the
size of the array or list. (One would expect the relative efficiency advantage of the
array over the list to increase with the number of elements being sorted.) Also if
you have a choice between a default build and a release build, use the release build
for the measurement.With today’s speedy computers, you probably will need to use
as large an array as possible to get meaningful readings.You might try, for example,
100,000 elements, 1,000,000 elements, and 10,000,000 elements.
*/

#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

int main()
{
	std::srand(static_cast<unsigned>(std::time(nullptr)));

	size_t size = 100000;
	std::vector<int> vi0(size);

	for (size_t i = 0; i < size; i++)
		vi0[i] = rand();

	clock_t beforeOperationRuns, afterOperationRuns;
	double operation1;
	double operation2;
	double operation3;

	std::vector<int> vi(vi0);
	std::list<int> li(vi0.cbegin(), vi0.cend());

	beforeOperationRuns = std::clock();
	std::sort(vi.begin(), vi.end());
	afterOperationRuns = std::clock();

	operation1 = static_cast<double>((afterOperationRuns - beforeOperationRuns)) / CLOCKS_PER_SEC;

	beforeOperationRuns = std::clock();
	li.sort();
	afterOperationRuns = std::clock();

	operation2 = static_cast<double>((afterOperationRuns - beforeOperationRuns)) / CLOCKS_PER_SEC;

	std::cout << "Vector sorting run time: " << operation1 << std::endl;
	std::cout << "List sorting run time: " << operation2 << std::endl;

	li = std::list<int>(vi0.cbegin(), vi0.cend());

	beforeOperationRuns = std::clock();
	vi = std::vector<int>(li.cbegin(), li.cend());
	std::sort(vi.begin(), vi.end());
	li = std::list<int>(vi.cbegin(), vi.cend());
	afterOperationRuns = std::clock();

	operation3 = static_cast<double>((afterOperationRuns - beforeOperationRuns)) / CLOCKS_PER_SEC;
	std::cout << "copy to vector -> sort vector -> copy to list time: " << operation3 << std::endl;

	return 0;
}