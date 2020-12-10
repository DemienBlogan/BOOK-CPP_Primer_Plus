#include <iostream>
#include "Cpmv.h"

Cpmv::Cpmv()
	: pi(nullptr)
{ }

Cpmv::Cpmv(std::string q, std::string z)
	: pi(new Info{ q, z })
{ }

Cpmv::Cpmv(const Cpmv& cp)
	: pi(nullptr)
{
	if (cp.pi != nullptr)
		pi = new Info{ cp.pi->qcode, cp.pi->zcode };
}

Cpmv::Cpmv(Cpmv&& mv) noexcept
	: pi(mv.pi)
{
	mv.pi = nullptr;
}

Cpmv::~Cpmv()
{
	delete pi;
	pi = nullptr;
}

void Cpmv::Display() const
{
	if (pi == nullptr)
		std::cout << "Empty\n";
	else
		std::cout << pi->qcode << "-" << pi->zcode << std::endl;
}

Cpmv& Cpmv::operator=(const Cpmv& cp)
{
	if (this != &cp)
	{
		delete[] this->pi;
		this->pi = cp.pi == nullptr ? nullptr : new Info{ cp.pi->qcode, cp.pi->zcode };
	}

	return *this;
}

Cpmv& Cpmv::operator=(Cpmv&& mv) noexcept
{
	if (this != &mv)
	{
		this->pi = mv.pi;
		mv.pi = nullptr;
	}

	return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const
{
	if (this->pi == nullptr && obj.pi == nullptr)
		return Cpmv();
	else if (this->pi == nullptr)
		return Cpmv(obj);
	else if (obj.pi == nullptr)
		return Cpmv(*this);
	else
		return Cpmv(this->pi->qcode + obj.pi->qcode, this->pi->zcode + obj.pi->zcode);
}