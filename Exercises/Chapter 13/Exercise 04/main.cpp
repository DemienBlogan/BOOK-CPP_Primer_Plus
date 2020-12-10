/*
4. The Benevolent Order of Programmers maintains a collection of bottled port.To
describe it, the BOP Portmaster has devised a Port class, as declared here:

#include <iostream>
using namespace std;
class Port
{
private:
	char * brand;
	char style[20]; // i.e., tawny, ruby, vintage
	int bottles;
public:
	Port(const char * br = "none", const char * st = "none", int b = 0);
	Port(const Port & p); // copy constructor

	virtual ~Port() { delete [] brand; }

	Port & operator=(const Port & p);
	Port & operator+=(int b); // adds b to bottles
	Port & operator-=(int b); // subtracts b from bottles, if available

	int BottleCount() const { return bottles; }
	virtual void Show() const;

	friend ostream & operator<<(ostream & os, const Port & p);
};

The Show() method presents information in the following format:
Brand: Gallo
Kind: tawny
Bottles: 20

The operator<<() function presents information in the following format (with no
newline character at the end):
Gallo, tawny, 20

The Portmaster completed the method definitions for the Port class and then
derived the VintagePort class as follows before being relieved of his position for
accidentally routing a bottle of ’45 Cockburn to someone preparing an experimental
barbecue sauce:

class VintagePort : public Port // style necessarily = "vintage"
{
private:
	char * nickname; // i.e., "The Noble" or "Old Velvet", etc.
	int year;        // vintage year

public:
	VintagePort();
	VintagePort(const char * br, int b, const char * nn, int y);
	VintagePort(const VintagePort & vp);

	~VintagePort() { delete [] nickname; }

	VintagePort & operator=(const VintagePort & vp);

	void Show() const;

	friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

You get the job of completing the VintagePort work.
	a. Your first task is to re-create the Port method definitions because the former
       Portmaster immolated his upon being relieved.
	b. Your second task is to explain why certain methods are redefined and others
       are not.
	c. Your third task is to explain why operator=() and operator<<() are not
       virtual.
	d. Your fourth task is to provide definitions for the VintagePort methods.
*/

#include <iostream>
#include "VintagePort.h"

int main()
{
	Port portObject{ "Liquer", "Bono", 3 };
	VintagePort vintagePortObject{ "Vodka", 30, "San-Trope", 1923 };

	std::cout << "--- Objects ---\n";
	std::cout << "- Port Object:\n";
	portObject.Show();
	std::cout << std::endl;
	std::cout << "Bottles = " << portObject.BottleCount() << std::endl;
	std::cout << portObject << "\n\n";

	std::cout << "- VintagePort Object:\n";
	vintagePortObject.Show();
	std::cout << std::endl;
	std::cout << "Bottles = " << vintagePortObject.BottleCount() << std::endl;
	std::cout << vintagePortObject << "\n\n";

	std::cout << "--- Pointer ---\n";
	std::cout << "- Port Object:\n";
	Port* portPointer = &portObject;
	portPointer->Show();
	std::cout << std::endl;
	std::cout << "Bottles = " << portPointer->BottleCount() << std::endl;
	std::cout << *portPointer << "\n\n";

	std::cout << "- VintagePort Object:\n";
	portPointer = &vintagePortObject;
	portPointer->Show();
	std::cout << std::endl;
	std::cout << "Bottles = " << portPointer->BottleCount() << std::endl;
	std::cout << (const VintagePort&)(*portPointer) << "\n\n";

	return 0;
}