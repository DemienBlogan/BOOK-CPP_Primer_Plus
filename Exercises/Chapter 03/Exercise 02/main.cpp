/*
2. Write a short program that asks for your height in feet and inches and your weight
in pounds. (Use three variables to store the information.) Have the program report
your body mass index (BMI).To calculate the BMI, first convert your height in feet
and inches to your height in inches (1 foot = 12 inches).Then convert your height
in inches to your height in meters by multiplying by 0.0254.Then convert your
weight in pounds into your mass in kilograms by dividing by 2.2. Finally, compute
your BMI by dividing your mass in kilograms by the square of your height in
meters. Use symbolic constants to represent the various conversion factors.
*/

#include <iostream>

int main()
{
	using namespace std;

	cout << "Enter your height (feet): ";
	int feet;
	cin >> feet;

	cout << "Enter your height (inches): ";
	int inches;
	cin >> inches;

	cout << "Enter your weight (pounds): ";
	double pounds;
	cin >> pounds;

	const int INCHES_IN_FEET = 12;
	const double METERS_IN_ICNH = 0.0254;
	int height = (feet * INCHES_IN_FEET + inches) * METERS_IN_ICNH;

	const double POUNDS_IN_KG = 2.2;
	double weight = pounds / POUNDS_IN_KG;

	double bmi = weight / (height * height);

	cout << "Your BMI = " << bmi << endl;

	return 0;
}