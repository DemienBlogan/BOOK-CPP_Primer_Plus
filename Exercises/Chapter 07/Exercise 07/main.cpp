/*
7. Redo Listing 7.7, modifying the three array-handling functions to each use two
pointer parameters to represent a range.The fill_array() function, instead of
returning the actual number of items read, should return a pointer to the location
after the last location filled; the other functions can use this pointer as the second
argument to identify the end of the data.
*/

#include <iostream>

const int Max = 5;

// function prototypes
double* fill_array(double* begin, double* end);
void show_array(const double* begin, const double* end);
void revalue(double r, double* begin, double* end);

int main()
{
	using namespace std;

	double properties[Max];

	double* end = fill_array(properties, properties + Max);

	show_array(properties, end);

	if (end - properties != 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;

		while (!(cin >> factor)) // bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "Bad input; Please enter a number: ";
		}

		revalue(factor, properties, end);
		show_array(properties, end);
	}

	cout << "Done.\n";
	cin.get();
	cin.get();

	return 0;
}

double* fill_array(double* begin, double* end)
{
	using namespace std;

	double temp;
	int i = 0;

	while (begin != end)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;

		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;

			cout << "Bad input; input process terminated.\n";
			break;
		}
		else if (temp < 0)
			break;

		*begin = temp;
		begin++;
		i++;
	}

	return begin;
}

void show_array(const double* begin, const double* end)
{
	using namespace std;
	int i = 0;

	while (begin != end)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << *begin << endl;

		begin++;
		i++;
	}
}

void revalue(double r, double* begin, double* end)
{
	while (begin != end)
		*(begin++) *= r;
}