#include <iostream>
#include "emp.h"

abstr_emp::abstr_emp(const std::string& fn, const std::string& ln, const std::string& j)
    : fname(fn), lname(ln), job(j)
{ }

void abstr_emp::ShowAll() const
{
    std::cout << "First name: " << fname << std::endl;
    std::cout << "Last name: " << lname << std::endl;
    std::cout << "Job title: " << job << std::endl;
}

void abstr_emp::SetAll()
{
    std::cout << "Enter first name: ";
    std::getline(std::cin, fname);

    std::cout << "Enter last name: ";
    std::getline(std::cin, lname);

    std::cout << "Enter job title: ";
    std::getline(std::cin, job);
}

std::ostream& operator<<(std::ostream& os, const abstr_emp& e)
{
    os << e.fname << " " << e.lname;
    return os;
}

abstr_emp::~abstr_emp()
{ }

employee::employee(const std::string& fn, const std::string& ln, const std::string& j)
    : abstr_emp(fn, ln, j)
{ }

void employee::ShowAll() const
{
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

manager::manager()
    : inchargeof(0)
{ }

manager::manager(const std::string& fn, const std::string& ln, const std::string& j, int ico)
    : abstr_emp(fn, ln, j), inchargeof(ico)
{ }

manager::manager(const abstr_emp& e, int ico)
    : abstr_emp(e), inchargeof(ico)
{ }

manager::manager(const manager& m)
    : abstr_emp(m), inchargeof(m.inchargeof)
{ }

void manager::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "In charge of " << inchargeof << " employees.\n";
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter employees which this employee is in charge of: ";
    int newInChargeOf;
    std::cin >> newInChargeOf;

    std::cin.ignore();

    InChargeOf() = newInChargeOf;
}

fink::fink()
    : reportsto("Nobody")
{ }

fink::fink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo)
    : abstr_emp(fn, ln, j), reportsto(rpo)
{ }

fink::fink(const abstr_emp& e, const std::string& rpo)
    : abstr_emp(e), reportsto(rpo)
{ }

fink::fink(const fink& e)
    : abstr_emp(e), reportsto("Nobody")
{ }

void fink::ShowAll() const
{
    abstr_emp::ShowAll();
    std::cout << "Fink reports to " << reportsto << std::endl;
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Enter new employee to whom fink reports: ";
    std::string employee;
    std::getline(std::cin, employee);

    ReportsTo() = employee;
}

highfink::highfink(const std::string& fn, const std::string& ln, const std::string& j, const std::string& rpo, int ico)
    : abstr_emp(fn, ln, j), fink(fn, ln, j, rpo), manager(fn, ln, j, ico)
{ }

highfink::highfink(const abstr_emp& e, const std::string& rpo, int ico)
    : abstr_emp(e), fink(e, rpo), manager(e, ico)
{ }

highfink::highfink(const fink& f, int ico)
    : abstr_emp(f), fink(f), manager(f, ico)
{ }

highfink::highfink(const manager& m, const std::string& rpo)
    : abstr_emp(m), fink(m, rpo), manager(m)
{ }

highfink::highfink(const highfink& h)
    : abstr_emp(h), fink(h), manager(h)
{ }

void highfink::ShowAll() const
{
    abstr_emp::ShowAll();   
    std::cout << "In charge of " << InChargeOf() << " employees.\n";
    std::cout << "Fink reports to " << ReportsTo() << std::endl;
}

void highfink::SetAll()
{
    abstr_emp::SetAll();

    std::cout << "Enter employees which this employee is in charge of: ";
    int newInChargeOf;
    std::cin >> newInChargeOf;

    std::cin.ignore();

    InChargeOf() = newInChargeOf;
    std::cout << "Enter new employee to whom fink reports: ";
    std::string employee;
    std::getline(std::cin, employee);

    ReportsTo() = employee;
}