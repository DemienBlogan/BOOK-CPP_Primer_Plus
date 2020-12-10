#include <iostream>
#include <iomanip>
#include "Wine.h"

Wine::Wine(const char* label, int yearsAmount, const int yearsArray[], const int bottlesArray[])
	: label(label), yearsBottles(ArrayInt(yearsArray, yearsAmount), ArrayInt(bottlesArray, yearsAmount))
{ }

Wine::Wine(const char* label, int yearsAmount)
	: label(label), yearsBottles(ArrayInt(yearsAmount), ArrayInt(yearsAmount))
{ }

void Wine::GetBottles()
{
	auto& years = yearsBottles.first();
	auto& bottles = yearsBottles.second();
	size_t size = years.size();

	std::cout << "Enter " << label << " data for " << size << " year(s):\n";

	for (size_t i = 0; i < size; i++)
	{
		std::cout << "Enter year: ";
		std::cin >> years[i];

		std::cout << "Enter bottles for that year: ";
		std::cin >> bottles[i];
	}
}

void Wine::Show() const
{
	const auto& years = yearsBottles.first();
	const auto& bottles = yearsBottles.second();

	std::cout << "Wine: " << label << std::endl;

	std::cout << "Year Bottles\n";
	for (size_t i = 0; i < years.size(); i++)
		std::cout << std::setw(4) << years[i] << " " << std::setw(-4) << bottles[i] << std::endl;
}

int Wine::sum() const
{
	return yearsBottles.second().sum();
}