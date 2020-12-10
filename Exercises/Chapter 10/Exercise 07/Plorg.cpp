#include <iostream>
#include <cstring>

#include "Plorg.h"

using std::cout;
using std::endl;

Plorg::Plorg(const char* name)
{
	if (name != nullptr && strlen(name) < LENGTH)
		strcpy_s(m_name, LENGTH, name);

	m_ci = 50;
}

void Plorg::ChangeCI(int ci)
{
	m_ci = ci;
}

void Plorg::Report() const
{
	cout << "Name: " << m_name << endl;
	cout << "CI: " << m_ci << endl;
}