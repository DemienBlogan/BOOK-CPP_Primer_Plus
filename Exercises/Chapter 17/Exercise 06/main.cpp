/*
6. Consider the class definitions of Programming Exercise 5 in Chapter 14,“Reusing
Code in C++”. If you haven’t yet done that exercise, do so now.Then do the
following:
Write a program that uses standard C++ I/O and file I/O in conjunction with data
of types employee, manager, fink, and highfink, as defined in Programming Exercise
5 in Chapter 14.The program should be along the general lines of Listing 17.17
in that it should let you add new data to a file.The first time through, the program
should solicit data from the user, show all the entries, and save the information in a
file. On subsequent uses, the program should first read and display the file data, let the
user add data, and show all the data. One difference is that data should be handled by
an array of pointers to type employee.That way, a pointer can point to an employee
object or to objects of any of the three derived types. Keep the array small to facilitate
checking the program; for example, you might limit the array to 10 elements:

const int MAX = 10; // no more than 10 objects
...
employee * pc[MAX];

For keyboard entry, the program should use a menu to offer the user the choice of
which type of object to create.The menu should use a switch to use new to create
an object of the desired type and to assign the object’s address to a pointer in the pc
array.Then that object can use the virtual setall() function to elicit the appropriate
data from the user:
pc[i]->setall(); // invokes function corresponding to type of object

To save the data to a file, devise a virtual writeall() function for that purpose:
for (i = 0; i < index; i++)
	pc[i]->writeall(fout);// fout ofstream connected to output file

NOTE: Use text I/O, not binary I/O, for Programming Exercise 6. (Unfortunately, virtual objects
include pointers to tables of pointers to virtual functions, and write() copies this information
to a file. An object filled by using read() from the file gets weird values for the function
pointers, which really messes up the behavior of virtual functions.) Use a newline character
to separate each data field from the next; this makes it easier to identify fields on input. Or
you could still use binary I/O, but not write objects as a whole. Instead, you could provide
class methods that apply the write() and read() functions to each class member individually
rather than to the object as a whole. That way, the program could save just the
intended data to a file.

The tricky part is recovering the data from the file.The problem is, how can the
program know whether the next item to be recovered is an employee object, a
manager object, a fink type, or a highfink type? One approach is, when writing
the data for an object to a file, precede the data with an integer that indicates the
type of object to follow.Then, on file input, the program can read the integer and
then use switch to create the appropriate object to receive the data:
enum classkind{ Employee, Manager, Fink, Highfink }; // in class header
...
int classtype;
while((fin >> classtype).get(ch)) // newline separates int from data
{
	switch(classtype)
	{
	case Employee : pc[i] = new employee;
					break;

Then you can use the pointer to invoke a virtual getall() function to read the
information:
pc[i++]->getall();
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "emp.h"

void ShowMenu();
void ClearBuffer();

int main()
{
	const int MAX_EMPL_COUNT = 10;
	abstr_emp* employees[MAX_EMPL_COUNT];

	std::cout << "You can enter of to " << MAX_EMPL_COUNT << " employees\n";

	int readEmployeesCount = 0;
	char ch;

	std::string filename{ "employeeList.txt" };
	std::ifstream file{ filename };

	if (file.is_open())
	{
		int classTypeInteger;

		while ((file >> classTypeInteger).get(ch))
		{
			switch (classTypeInteger)
			{
			case ClassKind::EMPLOYEE:
				employees[readEmployeesCount] = new employee;
				employees[readEmployeesCount]->ReadAll(file);
				readEmployeesCount++;
				break;

			case ClassKind::MANAGER:
				employees[readEmployeesCount] = new manager;
				employees[readEmployeesCount]->ReadAll(file);
				readEmployeesCount++;
				break;

			case ClassKind::FINK:
				employees[readEmployeesCount] = new fink;
				employees[readEmployeesCount]->ReadAll(file);
				readEmployeesCount++;
				break;

			case ClassKind::HIGHFINK:
				employees[readEmployeesCount] = new highfink;
				employees[readEmployeesCount]->ReadAll(file);
				readEmployeesCount++;
				break;

			default:
				std::cerr << "Incorrect type of employee\n";
				break;
			}
		}

		std::cout << "Current employee list:\n";

		for (int i = 0; i < readEmployeesCount; i++)
		{
			std::cout << "Employee #" << i + 1 << ":\n";
			employees[i]->ShowAll();
			std::cout << std::endl;
		}

		file.close();
	}

	char menuItem;

	while (readEmployeesCount < MAX_EMPL_COUNT)
	{
		ShowMenu();
		std::cin >> menuItem;
		ClearBuffer();

		switch (menuItem)
		{
		case 'a':
			employees[readEmployeesCount] = new employee;
			employees[readEmployeesCount]->SetAll();
			readEmployeesCount++;
			break;
		case 'b':
			employees[readEmployeesCount] = new manager;
			employees[readEmployeesCount]->SetAll();
			readEmployeesCount++;
			break;

		case 'c':
			employees[readEmployeesCount] = new fink;
			employees[readEmployeesCount]->SetAll();
			readEmployeesCount++;
			break;

		case 'd':
			employees[readEmployeesCount] = new highfink;
			employees[readEmployeesCount]->SetAll();
			readEmployeesCount++;
			break;

		case 'q': // Quit
			break;

		default:
			std::cout << "Incorrect menu item. Try again.\n";
			continue;
		}

		if (menuItem == 'q')
			break;
	}

	std::ofstream fout{ filename };

	if (!fout.is_open())
	{
		std::cerr << "Cannot open flle '" << filename << "'\n";
		return 1;
	}

	std::cout << "Updated list:\n";

	for (int i = 0; i < readEmployeesCount; i++)
	{
		employees[i]->ShowAll();
		std::cout << std::endl;

		employees[i]->WriteAll(fout);
	}

	fout.close();

	return 0;
}

void ShowMenu()
{
	std::cout << std::left;
	std::cout << std::setw(20) << "a. Employee" << std::setw(20) << "b. Manager" << std::endl;;
	std::cout << std::setw(20) << "c. Fink" <<  std::setw(20) << "d. Highfink" << std::endl;
	std::cout << "(q to quit) \n";
}

void ClearBuffer()
{
	while (std::cin.get() != '\n')
		continue;
}