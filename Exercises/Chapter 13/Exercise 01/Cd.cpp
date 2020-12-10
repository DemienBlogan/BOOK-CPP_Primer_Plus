#include <cstring>
#include <iostream>
#include "Cd.h"

Cd::Cd(const char* performers, const char* label, int selections, double playtime)
	: selections(selections), playtime(playtime)
{
	std::strcpy(this->performers, performers);
	std::strcpy(this->label, label);
}

Cd::Cd(const Cd& other)
	: selections(other.selections), playtime(other.playtime)
{
	std::strcpy(this->performers, other.performers);
	std::strcpy(this->label, other.label);
}

Cd::Cd()
	: performers("None"), label("None"), selections(0), playtime(0)
{ }

Cd::~Cd()
{ }

void Cd::Report() const
{
	std::cout << "Performers: " << performers << std::endl;
	std::cout << "Label: " << label << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}

Cd& Cd::operator=(const Cd& other)
{
	if (this != &other)
	{
		std::strcpy(this->performers, other.performers);
		std::strcpy(this->label, other.label);
		this->selections = other.selections;
		this->playtime = other.playtime;
	}

	return *this;
}