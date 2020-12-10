#include <iostream>
#include <cstring>

#include "Person.h"

using std::cout;

Person::Person(const string& ln, const char* fn)
	: lname(ln), fname("")
{
	if (fn != nullptr && strlen(fn) < LIMIT)
		strcpy_s(fname, LIMIT, fn);
}

void Person::Show() const
{
	cout << fname << " " << lname;
}

void Person::FormalShow() const
{
	cout << lname << ", " << fname;
}