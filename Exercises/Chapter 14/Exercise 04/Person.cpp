#include <iostream>
#include "Person.h"

Person::Person(const std::string& firstName, const std::string& lastName)
	: firstName(firstName), lastName(lastName)
{ }

void Person::Show() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name:  " << lastName << std::endl;
}

void Person::Set()
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);

	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
}