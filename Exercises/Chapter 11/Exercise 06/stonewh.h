// stonewh.h -- definition for the Stonewt class

#ifndef STONEWT_H_
#define STONEWT_H_

#include <iostream>

using std::ostream;

class Stonewt
{
public:
	enum Interpretation { STONE, INTEGER_POUNDS, FLOAT_POUNDS };

private:
	enum { Lbs_per_stn = 14 };    // pounds per stone
	int stone;                    // whole stones
	double pds_left;              // fractional pounds
	double pounds;                // entire weight in pounds
	Interpretation interpretation;

public:
	Stonewt(double lbs, Interpretation interpretation = STONE);
	Stonewt(int stn, double lbs, Interpretation interpretation = STONE);
	Stonewt();                    // default constructor
	~Stonewt();

	void ChangeInterpretation(Interpretation interpretation);
	double GetPounds() const { return pounds; }

	friend Stonewt operator+(const Stonewt& stonewt1, const Stonewt& stonewt2);
	friend Stonewt operator-(const Stonewt& stonewt1, const Stonewt& stonewt2);
	friend Stonewt operator*(const Stonewt& stonewt1, const Stonewt& stonewt2);
	friend ostream& operator<<(ostream& out, const Stonewt& stonewt);

	bool operator==(const Stonewt& stonewt) const;
	bool operator!=(const Stonewt& stonewt) const;
	bool operator>(const Stonewt& stonewt) const;
	bool operator<(const Stonewt& stonewt) const;
	bool operator>=(const Stonewt& stonewt) const;
	bool operator<=(const Stonewt& stonewt) const;
};

#endif