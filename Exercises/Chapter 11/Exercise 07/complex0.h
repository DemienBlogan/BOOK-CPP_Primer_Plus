#pragma once

#include <iostream>

using std::istream;
using std::ostream;

class complex
{
private:
	double real;
	double imagine;

public:
	complex(double real = 0.0, double imagine = 0.0)
		: real(real), imagine(imagine)
	{ }

	complex& operator~()
	{
		imagine = -imagine;
		return *this;
	}

	friend complex operator+(const complex& complex1, const complex& complex2)
	{
		double real = complex1.real + complex2.real;
		double imagine = complex1.imagine + complex2.imagine;
		return complex{ real, imagine };
	}

	friend complex operator-(const complex& complex1, const complex& complex2)
	{
		double real = complex1.real - complex2.real;
		double imagine = complex1.imagine - complex2.imagine;
		return complex{ real, imagine };
	}

	friend complex operator*(const complex& complex1, const complex& complex2)
	{
		double real = complex1.real * complex2.real - complex1.imagine * complex2.imagine;
		double imagine = complex1.real * complex2.imagine + complex1.imagine * complex2.real;
		return complex{ real, imagine };
	}

	friend complex operator*(const complex& c, double value)
	{
		double real = c.real * value;
		double imagine = c.imagine * value;
		return complex{ real, imagine };
	}

	friend complex operator*(double value, const complex& c)
	{
		double real = value * c.real;
		double imagine = value * c.imagine;
		return complex{ real, imagine };
	}

	friend ostream& operator<<(ostream& out, const complex& c)
	{
		out << "(" << c.real << ", " << c.imagine << "i)";
		return out;
	}

	friend istream& operator>>(istream& in, complex& c)
	{
		in >> c.real >> c.imagine;
		return in;
	}
};