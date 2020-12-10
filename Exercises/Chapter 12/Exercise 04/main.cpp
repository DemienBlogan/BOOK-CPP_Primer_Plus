/*
4. Consider the following variation of the Stack class defined in Listing 10.10:
// stack.h -- class declaration for the stack ADT
typedef unsigned long Item;
class Stack
{
private:
	enum {MAX = 10};    // constant specific to class
	Item * pitems;      // holds stack items
	int size;           // number of elements in stack
	int top;            // index for top stack item
public:
	Stack(int n = MAX); // creates stack with n elements
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;

	// push() returns false if stack already is full, true otherwise
	bool push(const Item & item); // add item to stack

	// pop() returns false if stack already is empty, true otherwise
	bool pop(Item & item); // pop top into item

	Stack & operator=(const Stack & st);
};
As the private members suggest, this class uses a dynamically allocated array to hold
the stack items. Rewrite the methods to fit this new representation and write a
program that demonstrates all the methods, including the copy constructor and
assignment operator.
*/

#include <iostream>

#include "stack.h"

using std::cout;
using std::cin;

int main()
{
	cout << "Enter max size of the stack: ";
	int maxSize;
	cin >> maxSize;

	Stack stack{ maxSize };
	char menuItem;

	unsigned long value;

	do
	{
		cout << "1 - Push value \n";
		cout << "2 - Pop value  \n";
		cout << "0 - Quit       \n";
		cin >> menuItem;

		switch (menuItem)
		{
		case '0':
			// No code
			break;

		case '1':
			cout << "Enter value: ";
			cin >> value;

			if (!stack.push(value))
				cout << "Stack is full.\n";
			else
				cout << "Value was pushed!\n";
			break;

		case '2':
			if (!stack.pop(value))
				cout << "Stack is empty.\n";
			else
				cout << "Value " << value << " was popped.\n";
			break;

		default:
			cout << "Incorrect item.\n";
			break;
		}

	} while (menuItem != '0');

	Stack stack2{ stack };

	cout << "Stack2: ";
	while (stack2.pop(value))
		cout << value << " ";
	cout << "\n";

	Stack stack3;
	stack3 = stack;

	cout << "Stack2: ";
	while (stack3.pop(value))
		cout << value << " ";
	cout << "\n";

	return 0;
}