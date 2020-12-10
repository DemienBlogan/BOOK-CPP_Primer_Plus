/*
10. Modify Listing 16.9 (vect3.cpp) as follows:

a. Add a price member to the Review structure.

b. Instead of using a vector of Review objects to hold the input, use a vector
of shared_ptr<Review> objects. Remember that a shared_ptr has to be
initialized with a pointer returned by new.

c. Follow the input stage with a loop that allows the user the following options
for displaying books: in original order, in alphabetical order, in order of
increasing ratings, in order of decreasing ratings, in order of increasing price,
in order of decreasing price, and quitting.

Here’s one possible approach.After getting the initial input, create another vector of
shared_ptrs initialized to the original array. Define an operator<() function that
compares pointed-to structures and use it to sort the second vector so that the
shared_ptrs are in the order of the book names stored in the pointed-to objects.
Repeat the process to get vectors of shared_ptrs sorted by rating and by price.
Note that rbegin() and rend() save you the trouble of also creating vectors of
reversed order.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Review
{
	std::string title;
	int rating;
	double price;
};

bool operator<(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool CompareInAlphabeticalOrder(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool CompareInIncreasingRatings(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool CompareInDecreasingRatings(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool CompareInIncreasingPrices(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);
bool CompareInDecreasingPrices(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2);

bool FillReview(Review& rr);
void ShowReview(const std::shared_ptr<Review>& rr);
void ShowMenu();
char SelectMenuItem();

int main()
{
	using namespace std;

	vector<shared_ptr<Review>> books;
	Review temp;
	char menuItem;

	while (FillReview(temp))
		books.push_back(std::make_shared<Review>(temp));

	if (books.size() > 0)
	{
		do
		{
			ShowMenu();
			menuItem = SelectMenuItem();
			system("cls");

			switch (menuItem)
			{
			case '0':
				continue;
			case '1':
				std::sort(books.begin(), books.end());
				std::cout << "Rating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case '2':
				std::sort(books.begin(), books.end(), CompareInAlphabeticalOrder);
				std::cout << "Rating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case '3':
				std::sort(books.begin(), books.end(), CompareInIncreasingRatings);
				std::cout << "Rating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case '4':
				std::sort(books.begin(), books.end(), CompareInDecreasingRatings);
				std::cout << "Rating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case '5':
				std::sort(books.begin(), books.end(), CompareInIncreasingPrices);
				std::cout << "Rating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			case '6':
				std::sort(books.begin(), books.end(), CompareInDecreasingPrices);
				std::cout << "Rating\tBook\tPrice\n";
				for_each(books.begin(), books.end(), ShowReview);
				break;
			default:
				cout << "Incorrect input. Try again.\n";
				break;
			}

		} while (menuItem != '0');

	}
	else
		cout << "No entries. ";

	cout << "Bye.\n";

	return 0;
}

bool operator<(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	return r1->title <= r2->title ? true : false;
}

bool CompareInAlphabeticalOrder(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	return r1 < r2;
}

bool CompareInIncreasingRatings(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	return r1->rating <= r2->rating ? true : false;
}

bool CompareInDecreasingRatings(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	return !CompareInIncreasingRatings(r1, r2);
}

bool CompareInIncreasingPrices(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	return r1->price <= r2->price ? true : false;
}

bool CompareInDecreasingPrices(const std::shared_ptr<Review>& r1, const std::shared_ptr<Review>& r2)
{
	return !CompareInIncreasingPrices(r1, r2);
}

bool FillReview(Review& rr)
{
	std::cout << "Enter book title (quit to quit): ";
	std::getline(std::cin, rr.title);

	if (rr.title == "quit")
		return false;

	std::cout << "Enter book rating: ";
	std::cin >> rr.rating;

	if (!std::cin)
		return false;

	std::cout << "Enter book price: $";
	std::cin >> rr.price;

	if (!std::cin)
		return false;

	// get rid of rest of input line
	while (std::cin.get() != '\n')
		continue;

	return true;
}

void ShowReview(const std::shared_ptr<Review>& rr)
{
	std::cout << rr->rating << "\t" << rr->title << "\t" << rr->price << std::endl;
}

void ShowMenu()
{
	std::cout << "1 - Original Order              \n";
	std::cout << "2 - Alphabetical Order          \n";
	std::cout << "3 - Order of increasing ratings \n";
	std::cout << "4 - Order of decreasing ratings \n";
	std::cout << "5 - Order of increasing prices  \n";
	std::cout << "6 - Order of decreasing prices  \n";
	std::cout << "0 - Quit                        \n";
}

char SelectMenuItem()
{
	char menuItem;
	std::cin >> menuItem;

	while (std::cin.get() != '\n')
		continue;

	return menuItem;
}