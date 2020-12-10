/*
6. Here’s a class declaration:
class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0); // sets x, y to a, b
	showmove() const;                 // shows current x, y values
	Move add(const Move & m) const;

	// this function adds x of m to x of invoking object to get new x,
	// adds y of m to y of invoking object to get new y, creates a new
	// move object initialized to new x, y values and returns it
	reset(double a = 0, double b = 0); // resets x,y to a, b
};

Create member function definitions and a program that exercises the class.
*/

#include <iostream>
#include "Move.h"

using std::cout;

int main()
{
	Move point1;
	Move point2{ 10, 20 };
	Move point3{ 50 };

	cout << "Show three points:\n";
	point1.ShowMove();
	point2.ShowMove();
	point3.ShowMove();

	cout << "Add point2 and point3 into point1:\n";
	point1 = point2.Add(point3);
	point1.ShowMove();
	
	cout << "Reset point1:\n";
	point1.Reset(555, 444);
	point1.ShowMove();

	cout << "Reset point1:\n";
	point1.Reset(1000);
	point1.ShowMove();

	cout << "Reset point1:\n";
	point1.Reset();
	point1.ShowMove();
	
	return 0;
}