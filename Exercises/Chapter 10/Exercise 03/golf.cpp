#include <iostream>
#include <cstring>
#include "golf.h"

using std::cout;
using std::cin;
using std::endl;

Golf::Golf()
{
    cout << "Enter fullname: ";
    cin.getline(fullname, Length);

    cout << "Enter handicap: ";
    cin >> handicap;
    cin.ignore();
}

Golf::Golf(const char* name, int hc)
{
    strcpy_s(fullname, Length, name);
    this->handicap = hc;
}

void Golf::SetHandicap(int hc)
{
    handicap = hc;
}

void Golf::Show() const
{
    cout << "Fullname: " << fullname << ", HC = " << handicap << endl;
}