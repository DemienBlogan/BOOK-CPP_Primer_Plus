/*
5. Consider the following structure declaration:
struct customer 
{
	char fullname[35];
	double payment;
};

Write a program that adds and removes customer structures from a stack, represented
by a Stack class declaration. Each time a customer is removed, his or her
payment should be added to a running total, and the running total should be
reported. Note: You should be able to use the Stack class unaltered; just change the
typedef declaration so that Item is type customer instead of unsigned long.
*/

#include <iostream>
#include <cctype>
#include <string>

#include "Stack.h"

int main()
{
	using namespace std;

	Stack st; // create an empty stack
	char ch;
	double runningTotal = 0;
	customer userCustomer;

	cout << "Please enter A to add a customer,\n";
	cout << "P to remove a customer, or Q to quit.\n";
	while (cin >> ch && toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;

		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a':
			cout << "Enter customer's name: ";
			cin.getline(userCustomer.fullname, 35);
			cout << "Enter customer's payment: ";
			cin >> userCustomer.payment;
			cin.ignore();

			if (st.isfull())
				cout << "stack already full\n";
			else
				st.push(userCustomer);

			break;

		case 'P':
		case 'p':
			if (st.isempty())
				cout << "stack already empty\n";
			else
			{
				st.pop(userCustomer);
				cout << "Customer " << userCustomer.fullname << " was removed.\n";
				runningTotal += userCustomer.payment;
				cout << "Running total = " << runningTotal << endl;
			}

			break;
		}

		cout << "Please enter A to add a purchase order,\n";
		cout << "P to process a PO, or Q to quit.\n";
	}

	cout << "Bye\n";

	return 0;
}