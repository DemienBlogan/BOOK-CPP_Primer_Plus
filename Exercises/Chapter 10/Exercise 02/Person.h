#pragma once

#include <string>

using std::string;

class Person
{
private:
	static const size_t LIMIT = 25;
	string lname;      // Person's last name
	char fname[LIMIT]; // Person's first name

public:
	Person()
	{
		lname = "";
		fname[0] = '\0';
	}
	Person(const string& ln, const char* fn = "Heyyou");

	// the following methods display lname and fname
	void Show() const;       // firstname lastname format
	void FormalShow() const; // lastname, firstname format
};