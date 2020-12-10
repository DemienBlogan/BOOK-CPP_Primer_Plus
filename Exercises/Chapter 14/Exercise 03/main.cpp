/*
3. Define a QueueTp template.Test it by creating a queue of pointers-to-Worker (as
defined in Listing 14.10) and using the queue in a program similar to that in
Listing 14.12.
*/

#include <iostream>
#include <cstring>
#include "Worker.h"
#include "Queue.h"

const int SIZE = 5;

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;

	Queue<Worker*> workers;
	Worker* worker;
	char choice;

	do
	{
		cout << "Enter the employee category:\n";
		cout << "w: waiter s: singer ";
		cout << "t: singing waiter q: quit\n";
		cin >> choice;

		while (strchr("wstq", choice) == NULL)
		{
			cout << "Please enter a w, s, t, or q: ";
			cin >> choice;
		}

		if (choice == 'q')
			continue;

		switch (choice)
		{
		case 'w':
			worker = new Waiter;
			workers.Enqueue(worker);
			break;
		case 's':
			worker = new Singer;
			workers.Enqueue(worker);
			break;
		case 't':
			worker = new SingingWaiter;
			workers.Enqueue(worker);
			break;
		default:
			worker = nullptr;
			break;
		}

		cin.get();

		if (worker != nullptr)
			worker->Set();

	} while (choice != 'q');

	cout << "\nHere is your staff:\n";

	while (!workers.IsEmpty())
	{
		workers.Dequeue(worker);
		worker->Show();
		delete worker;
	}

	cout << "Bye.\n";

	return 0;
}