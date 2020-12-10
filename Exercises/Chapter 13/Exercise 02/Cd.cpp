#include <cstring>
#include <iostream>
#include "Cd.h"

Cd::Cd(const char* performers, const char* label, int selections, double playtime)
	: performers(nullptr), label(nullptr), selections(selections), playtime(playtime)
{
	if (performers != nullptr)
	{
		size_t length = std::strlen(performers);
		this->performers = new char[length + 1];
		std::strcpy(this->performers, performers);
	}

	if (label != nullptr)
	{
		size_t length = std::strlen(label);
		this->label = new char[length + 1];
		std::strcpy(this->label, label);
	}
}

Cd::Cd(const Cd& other)
	: performers(nullptr), label(nullptr), selections(other.selections), playtime(other.playtime)
{
	if (other.performers != nullptr)
	{
		size_t length = std::strlen(other.performers);
		this->performers = new char[length + 1];
		std::strcpy(this->performers, other.performers);
	}

	if (other.label != nullptr)
	{
		size_t length = std::strlen(other.label);
		this->label = new char[length + 1];
		std::strcpy(this->label, other.label);
	}
}

Cd::Cd()
	: performers(nullptr), label(nullptr), selections(0), playtime(0)
{ }

Cd::~Cd()
{
	if (performers != nullptr)
	{
		delete[] performers;
		performers = nullptr;
	}

	if (label != nullptr)
	{
		delete[] label;
		label = nullptr;
	}
}

void Cd::Report() const
{
	std::cout << "Performers: " << (performers != nullptr ? performers : "None") << std::endl;
	std::cout << "Label: " << (label != nullptr ? label : "None") << std::endl;
	std::cout << "Selections: " << selections << std::endl;
	std::cout << "Playtime: " << playtime << std::endl;
}

Cd& Cd::operator=(const Cd& other)
{
	if (this != &other)
	{
		delete[] performers;
		delete[] label;

		performers = nullptr;
		label = nullptr;

		if (other.performers != nullptr)
		{
			size_t length = std::strlen(other.performers);
			this->performers = new char[length + 1];
			std::strcpy(this->performers, other.performers);
		}

		if (other.label != nullptr)
		{
			size_t length = std::strlen(other.label);
			this->label = new char[length + 1];
			std::strcpy(this->label, other.label);
		}

		this->selections = other.selections;
		this->playtime = other.playtime;
	}

	return *this;
}