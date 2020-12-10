#include <iostream>
#include <iomanip>
#include "Wine.h"

Wine::Wine(const char* label, int yearsAmount, const int yearsArray[], const int bottlesArray[])
	: std::string(label), PairArray(ArrayInt(yearsArray, yearsAmount), ArrayInt(bottlesArray, yearsAmount))
{ }

Wine::Wine(const char* label, int yearsAmount)
	: std::string(label), PairArray(ArrayInt(yearsAmount), ArrayInt(yearsAmount))
{ }

void Wine::GetBottles()
{
	auto& years = static_cast<PairArray&>(*this).first();
	auto& bottles = static_cast<PairArray&>(*this).second();
	size_t size = years.size();
	const std::string& label = static_cast<const std::string&>(*this);

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
	const auto& years = static_cast<const PairArray&>(*this).first();
	const auto& bottles = static_cast<const PairArray&>(*this).second();
	size_t size = years.size();
	const std::string& label = static_cast<const std::string&>(*this);

	std::cout << "Wine: " << label << std::endl;

	std::cout << "Year Bottles\n";
	for (size_t i = 0; i < size; i++)
		std::cout << std::setw(4) << years[i] << " " << std::setw(-4) << bottles[i] << std::endl;
}

int Wine::sum() const
{
	const auto& bottles = static_cast<const PairArray&>(*this).second();
	return bottles.sum();
}