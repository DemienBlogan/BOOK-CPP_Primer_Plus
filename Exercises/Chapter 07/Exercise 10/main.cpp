/*
10. Design a function calculate() that takes two type double values and a pointer to
a function that takes two double arguments and returns a double.The
calculate() function should also be type double, and it should return the value
that the pointed-to function calculates, using the double arguments to
calculate(). For example, suppose you have this definition for the add()
function:

double add(double x, double y)
{
	return x + y;
}

Then, the function call in the following would cause calculate() to pass the values
2.5 and 10.4 to the add() function and then return the add() return value
(12.9):

double q = calculate(2.5, 10.4, add);

Use these functions and at least one additional function in the add() mold in a
program.The program should use a loop that allows the user to enter pairs of numbers.
For each pair, use calculate() to invoke add() and at least one other function.
If you are feeling adventurous, try creating an array of pointers to add()-style
functions and use a loop to successively apply calculate() to a series of functions
by using these pointers. Hint: Here’s how to declare such an array of three pointers:

double (*pf[3])(double, double);

You can initialize such an array by using the usual array initialization syntax and
function names as addresses.
*/

#include <iostream>

using namespace std;

double calculate(double value1, double value2, double (*operation)(double number1, double number2));
double Add(double number1, double number2);
double Substract(double number1, double number2);
double Product(double number1, double number2);
double Divide(double number1, double number2);

int main()
{
	const size_t FUNCTIONS = 4;
	double (*functions[FUNCTIONS])(double, double) = { Add, Substract, Product, Divide };

	double number1, number2;

	cout << "Enter two numbers (or 'q' to stop): ";
	cin >> number1 >> number2;
	while (cin)
	{
		double result;

		result = calculate(number1, number2, functions[0]);
		cout << number1 << " + " << number2 << " = " << result << endl;

		result = calculate(number1, number2, functions[1]);
		cout << number1 << " - " << number2 << " = " << result << endl;

		result = calculate(number1, number2, functions[2]);
		cout << number1 << " * " << number2 << " = " << result << endl;

		result = calculate(number1, number2, functions[3]);
		cout << number1 << " / " << number2 << " = " << result << endl;

		cout << "Enter next two numbers (or 'q' to stop): ";
		cin >> number1 >> number2;
	}

	return 0;
}

double calculate(double value1, double value2, double (*operation)(double number1, double number2))
{
	double result = operation(value1, value2);
	return result;
}

double Add(double number1, double number2)
{
	return number1 + number2;
}
double Substract(double number1, double number2)
{
	return number1 - number2;
}
double Product(double number1, double number2)
{
	return number1 * number2;
}
double Divide(double number1, double number2)
{
	return number1 / number2;
}