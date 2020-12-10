/*
2. Here is declaration for the Cpmv class:
class Cpmv
{
public:
	struct Info
	{
		std::string qcode;
		std::string zcode;
	};
private:
	Info *pi;
	public:
	Cpmv();
	Cpmv(std::string q, std::string z);
	Cpmv(const Cpmv & cp);
	Cpmv(Cpmv && mv);
	~Cpmv();
	Cpmv & operator=(const Cpmv & cp);
	Cpmv & operator=(Cpmv && mv);
	Cpmv operator+(const Cpmv & obj) const;
	void Display() const;
};

The operator+() function should create an object whose qcode and zcode members
concatenate the corresponding members of the operands. Provide code that
implements move semantics for the move constructor and the move assignment
operator.Write a program that uses all the methods. For testing purposes, make the
various methods verbose so that you can see when they are used.
*/

#include "Cpmv.h"

int main()
{
	Cpmv object1;
	Cpmv object2("123", "abc");
	Cpmv object3(object2);
	Cpmv object4(object2 + object3);
	Cpmv object5(std::move(object2));
	Cpmv object6;
	object6 = object3;
	Cpmv object7;
	object7 = std::move(object3);

	object1.Display();
	object2.Display();
	object3.Display();
	object4.Display();
	object5.Display();
	object6.Display();
	object7.Display();

	return 0;
}