#include "Port.h"

Port::Port(const char* brand, const char* style, int bottles)
	: brand(nullptr), style(""), bottles(0)
{
	if (brand != nullptr)
	{
		size_t length = std::strlen(brand);
		this->brand = new char[length + 1];
		std::strcpy(this->brand, brand);
	}

	if (style != nullptr)
	{
		size_t length = std::strlen(style);

		if (length < 20)
			std::strcpy(this->style, style);
	}

	if (bottles > 0)
		this->bottles = bottles;
}

Port::Port(const Port& other)
	: brand(nullptr), style(""), bottles(other.bottles)
{
	if (other.brand != nullptr)
	{
		size_t length = std::strlen(other.brand);
		this->brand = new char[length + 1];
		std::strcpy(this->brand, other.brand);
	}

	if (other.style != nullptr)
		std::strcpy(this->style, other.style);
}

void Port::Show() const
{
	std::cout << "Brand: " << (brand != nullptr ? brand : "") << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}

Port& Port::operator=(const Port& other)
{
	if (this != &other)
	{
		delete[] brand;
		brand = nullptr;
		if (other.brand != nullptr)
		{
			size_t length = std::strlen(other.brand);
			this->brand = new char[length + 1];
			std::strcpy(this->brand, other.brand);
		}

		if (other.style != nullptr)
			std::strcpy(this->style, other.style);
	}

	return *this;
}

Port& Port::operator+=(int bottles)
{
	if (bottles > 0)
		this->bottles += bottles;

	return *this;
}

Port& Port::operator-=(int bottles)
{
	if (bottles > 0 && bottles <= this->bottles)
		this->bottles -= bottles;

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Port& port)
{
	os << (port.brand != nullptr ? port.brand : "") << " " << port.style << ", " << port.bottles;
	return os;
}