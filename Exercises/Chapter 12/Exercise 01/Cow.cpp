#include <iostream>
#include <cstring>

#include "Cow.h"

Cow::Cow()
    : name("NULL-Cow"), hobby(nullptr), weight(0.0)
{ }

Cow::Cow(const char* name, const char* hobby, double weight)
	: name("NULL-Cow"), hobby(nullptr), weight(0.0)
{
	if (strlen(name) < 20)
		strcpy_s(this->name, 20, name);

	if (hobby != nullptr)
	{
		size_t length = strlen(hobby);
		this->hobby = new char[length + 1];
		strcpy_s(this->hobby, length + 1, hobby);
	}

	if (weight > 0.0)
		this->weight = weight;
}

Cow::Cow(const Cow& otherCow)
	: name("NULL-Cow"), hobby(nullptr), weight(otherCow.weight)
{
	strcpy_s(this->name, 20, otherCow.name);
	
	if (otherCow.hobby != nullptr)
	{
		size_t length = strlen(otherCow.hobby);
		this->hobby = new char[length + 1];
		strcpy_s(this->hobby, length + 1, otherCow.hobby);
	}
}

Cow::~Cow()
{
	delete[] hobby;
	hobby = nullptr;
}

Cow& Cow::operator=(const Cow& otherCow)
{
	if (this == &otherCow)
		return *this;

	strcpy_s(this->name, 20, otherCow.name);

	if (this->hobby != nullptr)
		delete[] hobby;

	if (otherCow.hobby != nullptr)
	{
		size_t length = strlen(otherCow.hobby);
		this->hobby = new char[length + 1];
		strcpy_s(this->hobby, length + 1, otherCow.hobby);
	}
	else
		this->hobby = nullptr;

	this->weight = otherCow.weight;

}

void Cow::ShowCow() const
{
	using std::cout;
	using std::endl;

	cout << "Name: " << name << endl;
	cout << "Hobby: " << (hobby != nullptr ? hobby : "No hobby") << endl;
	cout << "Weight: " << weight << endl;
}