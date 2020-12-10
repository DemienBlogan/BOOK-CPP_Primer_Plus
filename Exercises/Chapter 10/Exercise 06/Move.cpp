#include <iostream>
#include "Move.h"

using std::cout;
using std::endl;

Move::Move(double a, double b)
	: x(a), y(b)
{ }

void Move::ShowMove() const
{
	cout << "x = " << x << ", y = " << y << endl;
}

Move Move::Add(const Move& m) const
{
	return Move(this->x + m.x, this->y + m.y);
}

void Move::Reset(double a, double b)
{
	x = a;
	y = b;
}