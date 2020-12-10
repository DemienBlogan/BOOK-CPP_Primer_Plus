#include "VintagePort.h"

VintagePort::VintagePort(const char* brand, int bottles, const char* nickname, int year)
	: Port(brand, "vintage", bottles), nickname(nullptr), year(0)
{
	if (nickname != nullptr)
	{
		size_t length = std::strlen(nickname);
		this->nickname = new char[length + 1];
		std::strcpy(this->nickname, nickname);
	}

	if (year > 0)
		this->year = year;
}

VintagePort::VintagePort(const VintagePort& other)
	: Port(other), nickname(nullptr), year(other.year)
{
	if (other.nickname != nullptr)
	{
		size_t length = std::strlen(other.nickname);
		this->nickname = new char[length + 1];
		std::strcpy(this->nickname, other.nickname);
	}
}

VintagePort& VintagePort::operator=(const VintagePort& other)
{
	if (this != &other)
	{
		Port::operator=(other);

		delete[] nickname;
		nickname = nullptr;

		this->year = other.year;

		if (other.nickname != nullptr)
		{
			size_t length = std::strlen(other.nickname);
			this->nickname = new char[length + 1];
			std::strcpy(this->nickname, other.nickname);
		}
	}

	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	std::cout << "Nickname: " << (nickname != nullptr ? nickname : nullptr) << std::endl;
	std::cout << "Year: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vintagePort)
{
	std::cout << (const Port&)vintagePort << std::endl;
	os << (vintagePort.nickname != nullptr ? vintagePort.nickname : "") << ", year = " << vintagePort.year;
	return os;
}
