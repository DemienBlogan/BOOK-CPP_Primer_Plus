/*
8. Do Programming Exercise 7 but use new to allocate a structure instead of declaring
a structure variable.Also have the program request the pizza diameter before it
requests the pizza company name.
*/

#include <iostream>
#include <string>
using namespace std;

struct Pizza
{
	string company;
	double diameter;
	double weight;
};

int main()
{
	Pizza* pizza = new Pizza();

	cout << "Enter pizza diameter: ";
	cin >> pizza->diameter;
	cin.ignore();

	cout << "Enter company name: ";
	getline(cin, pizza->company);

	cout << "Enter pizza weight: ";
	cin >> pizza->weight;

	cout << "Pizza information:\n";
	cout << "Company: " << pizza->company << endl;
	cout << "Diameter: " << pizza->diameter << endl;
	cout << "Weight: " << pizza->weight << endl;

	delete pizza;

	return 0;
}