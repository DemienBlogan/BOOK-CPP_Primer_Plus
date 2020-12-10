// stonewt.cpp -- Stonewt methods

#include <iostream>

#include "stonewh.h"

using std::cout;

// construct Stonewt object from double value
Stonewt::Stonewt(double lbs, Interpretation interpretation)
{
	stone = int(lbs) / Lbs_per_stn; // integer division
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
	this->interpretation = interpretation;
}

// construct Stonewt object from stone, double values
Stonewt::Stonewt(int stn, double lbs, Interpretation interpretation)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
	this->interpretation = interpretation;
}

Stonewt::Stonewt() // default constructor, wt = 0
{
	stone = pounds = pds_left = 0;
	interpretation = STONE;
}

Stonewt::~Stonewt() // destructor
{ }

void Stonewt::ChangeInterpretation(Interpretation interpretation)
{
	this->interpretation = interpretation;
}

Stonewt operator+(const Stonewt& stonewt1, const Stonewt& stonewt2)
{
	return Stonewt{ stonewt1.pounds + stonewt2.pounds };
}

Stonewt operator-(const Stonewt& stonewt1, const Stonewt& stonewt2)
{
	return Stonewt{ stonewt1.pounds - stonewt2.pounds };
}

Stonewt operator*(const Stonewt& stonewt1, const Stonewt& stonewt2)
{
	return Stonewt{ stonewt1.pounds * stonewt2.pounds };
}

ostream& operator<<(ostream& out, const Stonewt& stonewt)
{
	switch (stonewt.interpretation)
	{
	case Stonewt::STONE:
		out << stonewt.stone << " stone, " << stonewt.pds_left << " pounds\n";
		break;

	case Stonewt::INTEGER_POUNDS:
		out << static_cast<int>(stonewt.pounds) << " pounds\n";
		break;

	case Stonewt::FLOAT_POUNDS:
		out << stonewt.pounds << " pounds\n";
		break;

	default:
		out << "Incorrect interpretation\n";
		break;
	}

	return out;
}