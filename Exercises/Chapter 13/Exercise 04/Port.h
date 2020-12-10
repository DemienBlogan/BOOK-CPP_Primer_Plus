#pragma once
#include <iostream>

class Port
{
private:
	char* brand;
	char style[20];
	int bottles;

public:
	Port(const char* brand = "none", const char* style = "none", int bottles = 0);
	Port(const Port& other);

	virtual ~Port()
	{
		delete[] brand;
	}

	int BottleCount() const { return bottles; }
	virtual void Show() const;

	Port& operator=(const Port& other);
	Port& operator+=(int bottles);
	Port& operator-=(int bottles);

	friend std::ostream& operator<<(std::ostream& os, const Port& port);
};