#include <iostream>
#include "Gunslinger.h"

void Gunslinger::ShowDrawTimeAndNotches() const
{
	std::cout << "Draw time: " << drawTime << std::endl;
	std::cout << "Notches: " << notches << std::endl;
}

Gunslinger::Gunslinger(const std::string& firstName, const std::string& lastName, int drawTime, int notches)
	: Person(firstName, lastName), drawTime(drawTime), notches(notches)
{ }

void Gunslinger::Show() const
{
	Person::Show();
	ShowDrawTimeAndNotches();
}

void Gunslinger::Set()
{
	Person::Set();

	std::cout << "Enter number of notches: ";
	std::cin >> notches;

	std::cout << "Enter draw time: ";
	std::cin >> drawTime;

	std::cin.ignore();
}