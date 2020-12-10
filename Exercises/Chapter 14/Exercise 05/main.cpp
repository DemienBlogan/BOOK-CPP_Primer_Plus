/*
5. Here are some class declarations:
// emp.h -- header file for abstr_emp class and children
#include <iostream>
#include <string>
class abstr_emp
{
private:
std::string fname; // abstr_emp's first name
std::string lname; // abstr_emp's last name
std::string job;
public:
abstr_emp();
abstr_emp(const std::string & fn, const std::string & ln,
const std::string & j);
virtual void ShowAll() const; // labels and shows all data
virtual void SetAll(); // prompts user for values
friend std::ostream &
operator<<(std::ostream & os, const abstr_emp & e);
// just displays first and last name
virtual ~abstr_emp() = 0; // virtual base class
};
class employee : public abstr_emp
{
public:
employee();
employee(const std::string & fn, const std::string & ln,
const std::string & j);
virtual void ShowAll() const;
virtual void SetAll();
};
class manager: virtual public abstr_emp
{
private:
int inchargeof; // number of abstr_emps managed
protected:
int InChargeOf() const { return inchargeof; } // output
int & InChargeOf(){ return inchargeof; } // input
public:
manager();
manager(const std::string & fn, const std::string & ln,
const std::string & j, int ico = 0);
manager(const abstr_emp & e, int ico);
manager(const manager & m);
virtual void ShowAll() const;
virtual void SetAll();
};

class fink: virtual public abstr_emp
{
private:
std::string reportsto; // to whom fink reports
protected:
const std::string ReportsTo() const { return reportsto; }
std::string & ReportsTo(){ return reportsto; }
public:
fink();
fink(const std::string & fn, const std::string & ln,
const std::string & j, const std::string & rpo);
fink(const abstr_emp & e, const std::string & rpo);
fink(const fink & e);
virtual void ShowAll() const;
virtual void SetAll();
};

class highfink: public manager, public fink // management fink
{
public:
highfink();
highfink(const std::string & fn, const std::string & ln,
const std::string & j, const std::string & rpo,
int ico);
highfink(const abstr_emp & e, const std::string & rpo, int ico);
highfink(const fink & f, int ico);
highfink(const manager & m, const std::string & rpo);
highfink(const highfink & h);
virtual void ShowAll() const;
virtual void SetAll();
};

Note that the class hierarchy uses MI with a virtual base class, so keep in mind the
special rules for constructor initialization lists for that case.Also note the presence
of some protected-access methods.This simplifies the code for some of the
highfink methods. (Note, for example, that if highfink::ShowAll() simply
calls fink::ShowAll() and manager::ShowAll(), it winds up calling
abstr_emp::ShowAll() twice.) Provide the class method implementations and test
the classes in a program. Here is a minimal test program:
// pe14-5.cpp
// useemp1.cpp -- using the abstr_emp classes
#include <iostream>
using namespace std;
#include "emp.h"
int main(void)
{
employee em("Trip", "Harris", "Thumper");
cout << em << endl;
em.ShowAll();
manager ma("Amorphia", "Spindragon", "Nuancer", 5);
cout << ma << endl;
ma.ShowAll();
fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
cout << fi << endl;
fi.ShowAll();
highfink hf(ma, "Curly Kew"); // recruitment?
hf.ShowAll();
cout << "Press a key for next phase:\n";
cin.get();
highfink hf2;
hf2.SetAll();
cout << "Using an abstr_emp * pointer:\n";
abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
for (int i = 0; i < 4; i++)
tri[i]->ShowAll();
return 0;
}

Why is no assignment operator defined?
Why are ShowAll() and SetAll() virtual?
Why is abstr_emp a virtual base class?
Why does the highfink class have no data section?
Why is only one version of operator<<() needed?
What would happen if the end of the program were replaced with this code?
abstr_emp tri[4] = {em, fi, hf, hf2};
for (int i = 0; i < 4; i++)
tri[i].ShowAll();
*/

#include <iostream>
#include "emp.h"

using namespace std;

int main()
{
	employee em("Trip", "Harris", "Thumper");
	cout << em << endl;

	em.ShowAll();

	manager ma("Amorphia", "Spindragon", "Nuancer", 5);
	cout << ma << endl;

	ma.ShowAll();

	fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
	cout << fi << endl;

	fi.ShowAll();

	highfink hf(ma, "Curly Kew");
	hf.ShowAll();

	cout << "Press a key for next phase:\n";
	cin.get();
	cin.get();

	highfink hf2;
	hf2.SetAll();

	cout << "Using an abstr_emp * pointer:\n";
	abstr_emp* tri[4] = { &em, &fi, &hf, &hf2 };

	for (int i = 0; i < 4; i++)
		tri[i]->ShowAll();

	return 0;
}