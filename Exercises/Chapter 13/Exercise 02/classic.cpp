#include <cstring>
#include <iostream>
#include "classic.h"

classic::classic()
	: Cd("None", "None", 0, 0), primaryWork(nullptr)
{ }

classic::classic(const char* primaryWork, const char* performers, const char* label, int selections, double playtime)
	: Cd(performers, label, selections, playtime), primaryWork(nullptr)
{
	if (primaryWork != nullptr)
	{
		size_t length = std::strlen(primaryWork);
		this->primaryWork = new char[length + 1];
		std::strcpy(this->primaryWork, primaryWork);
	}
}

classic::classic(const classic& other)
	: Cd(other), primaryWork(nullptr)
{
	if (other.primaryWork != nullptr)
	{
		size_t length = std::strlen(other.primaryWork);
		this->primaryWork = new char[length + 1];
		std::strcpy(this->primaryWork, other.primaryWork);
	}
}

classic::~classic()
{
	if (primaryWork != nullptr)
	{
		delete[] primaryWork;
		primaryWork = nullptr;
	}
}

void classic::Report() const
{
	Cd::Report();
	std::cout << "Primary work: " << (primaryWork != nullptr ? primaryWork : "None") << std::endl;
}

classic& classic::operator=(const classic& other)
{
	if (this != &other)
	{
		Cd::operator=(other);

		delete[] primaryWork;
		primaryWork = nullptr;

		if (other.primaryWork != nullptr)
		{
			size_t length = std::strlen(other.primaryWork);
			this->primaryWork = new char[length + 1];
			std::strcpy(this->primaryWork, other.primaryWork);
		}
	}

	return *this;
}