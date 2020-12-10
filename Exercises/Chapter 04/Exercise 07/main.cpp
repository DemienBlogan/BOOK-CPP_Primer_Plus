/*
7. William Wingate runs a pizza-analysis service. For each pizza, he needs to record
the following information:

- The name of the pizza company, which can consist of more than one word
- The diameter of the pizza
- The weight of the pizza

Devise a structure that can hold this information and write a program that uses a
structure variable of that type.The program should ask the user to enter each of the
preceding items of information, and then the program should display that information.
Use cin (or its methods) and cout.
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
	Pizza pizza;

	cout << "Enter company name: ";
	getline(cin, pizza.company);

	cout << "Enter pizza diameter: ";
	cin >> pizza.diameter;

	cout << "Enter pizza weight: ";
	cin >> pizza.weight;

	cout << "Pizza information:\n";
	cout << "Company: " << pizza.company << endl;
	cout << "Diameter: " << pizza.diameter << endl;
	cout << "Weight: " << pizza.weight << endl;

	return 0;
}