#include <cstring>
#include <iostream>
#include "classic.h"

classic::classic()
	: Cd("None", "None", 0, 0), primaryWork("None")
{ }

classic::classic(const char* primaryWork, const char* performers, const char* label, int selections, double playtime)
	: Cd(performers, label, selections, playtime)
{
	std::strcpy(this->primaryWork, primaryWork);
}

classic::classic(const classic& other)
	: Cd(other)
{
	std::strcpy(this->primaryWork, other.primaryWork);
}

classic::~classic()
{ }

void classic::Report() const
{
	Cd::Report();
	std::cout << "Primary work: " << primaryWork << std::endl;
}

classic& classic::operator=(const classic& other)
{
	if (this != &other)
	{
		Cd::operator=(other);
		std::strcpy(this->primaryWork, other.primaryWork);
	}

	return *this;
}