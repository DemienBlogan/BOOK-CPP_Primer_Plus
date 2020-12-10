/*
5. Rewrite the Stonewt class (Listings 11.16 and 11.17) so that it has a state member
that governs whether the object is interpreted in stone form, integer pounds form,
or floating-point pounds form. Overload the << operator to replace the
show_stn() and show_lbs() methods. Overload the addition, subtraction, and
multiplication operators so that one can add, subtract, and multiply Stonewt values.
Test your class with a short program that uses all the class methods and friends.
*/

#include <iostream>

#include "stonewh.h"

using std::cout;
using std::endl;

int main()
{
	Stonewt operand1{ 30.4, Stonewt::Interpretation::STONE };
	Stonewt operand2{ 30.4, Stonewt::Interpretation::FLOAT_POUNDS };
	Stonewt operand3{ 30.4, Stonewt::Interpretation::INTEGER_POUNDS };

	cout << "Operands:\n";
	cout << operand1 << endl;
	cout << operand2 << endl;
	cout << operand3 << endl;

	Stonewt sum = operand1 + operand2;
	Stonewt difference = operand1 - operand2;
	Stonewt product = operand1 * operand2;

	sum.ChangeInterpretation(Stonewt::Interpretation::FLOAT_POUNDS);
	difference.ChangeInterpretation(Stonewt::Interpretation::FLOAT_POUNDS);
	product.ChangeInterpretation(Stonewt::Interpretation::FLOAT_POUNDS);

	cout << "Sum: " << sum << endl;
	cout << "Difference: " << difference << endl;
	cout << "Product: " << product << endl;

	return 0;
}