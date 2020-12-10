#pragma once
#include <string>

class Person
{
private:
	std::string firstName;
	std::string lastName;

public:
	Person(const std::string& firstName = "", const std::string& lastName = "");
	
	virtual void Show() const;
	virtual void Set();

	virtual ~Person() = default;
};