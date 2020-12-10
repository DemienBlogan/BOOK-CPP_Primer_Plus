/*
3. Revise the baseDMA-lacksDMA-hasDMA class hierarchy so that all three classes are
derived from an ABC.Test the result with a program similar to the one in Listing
13.10.That is, it should feature an array of pointers to the ABC and allow the user
to make runtime decisions as to what types of objects are created.Add virtual
View() methods to the class definitions to handle displaying the data.
*/


#include <iostream>
#include <string>
#include "dma.h"

const int ARRAYS = 4;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::getline;

	abstractDMA* arrays[ARRAYS];
	std::string label;
	std::string color;
	std::string style;
	int rating;
	char choice;

	for (int i = 0; i < ARRAYS; i++)
	{
		cout << "Enter label: ";
		getline(cin, label);

		cout << "Enter rating: ";
		cin >> rating;

		cout << "Enter 1 to choose BaseDMA class, 2 to choose lacksDMA class, 3 to choose HasDMA class: ";

		while (cin >> choice && (choice != '1' && choice != '2' && choice != '3'))
			cout << "Enter either 1, 2, or 3: ";
		if (choice == '1')
			arrays[i] = new baseDMA(label.c_str(), rating);
		else if (choice == '2')
		{
			cout << "Enter color: ";
			cin.ignore();
			getline(cin, color);

			arrays[i] = new lacksDMA(color.c_str(), label.c_str(), rating);
		}
		else
		{
			cout << "Enter style: ";
			cin.ignore();
			getline(cin, style);

			arrays[i] = new hasDMA(style.c_str(), label.c_str(), rating);
		}

		while (cin.get() != '\n')
			continue;
	}
	cout << endl;

	for (int i = 0; i < ARRAYS; i++)
	{
		arrays[i]->View();
		cout << endl;
	}

	for (int i = 0; i < ARRAYS; i++)
		delete arrays[i];

	cout << "Done.\n";

	return 0;
}