#include <iostream>
#include <cstring>

#include "golf.h"

using namespace std;

void setgolf(golf& g, const char* name, int hc)
{
    strcpy_s(g.fullname, Len, name);
    g.handicap = hc;
}

int setgolf(golf& g)
{
    cout << "Enter fullname (empty string to stop): ";
    cin.getline(g.fullname, Len);

    if (g.fullname[0] == '\0')
        return 0;

    cout << "Enter handicap: ";
    cin >> g.handicap;
    cin.ignore();

    return 1;
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    cout << "Fullname: " << g.fullname << ", HC = " << g.handicap << endl;
}