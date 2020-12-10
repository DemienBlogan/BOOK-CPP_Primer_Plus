#pragma once

#include <string>

class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};

private:
	Info* pi;

public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv&& mv) noexcept;

	~Cpmv();

	void Display() const;

	Cpmv& operator=(const Cpmv& cp);
	Cpmv& operator=(Cpmv&& mv) noexcept;
	Cpmv operator+(const Cpmv& obj) const;
};