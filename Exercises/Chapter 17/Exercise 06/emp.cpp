#include <iostream>
#include "emp.h"

static void CheckInput(const std::istream& inputStream)
{
    if (!inputStream.good())
    {
        std::cout << "Input was broken.\n";
        std::exit(EXIT_FAILURE);
    }
}

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

void abstr_emp::WriteAll(std::ofstream& file) const
{
    file << "First name: " << fname << std::endl;
    file << "Last name:  " << lname << std::endl;
    file << "Job title:  " << job << std::endl;
}

void abstr_emp::ReadAll(std::ifstream& file)
{
    // Try to read first name.
    while (file.good() && file.get() != ':')
        continue;
    CheckInput(file);
    getline(file, fname);

    // Try to read last name.
    while (file.good() && file.get() != ':')
        continue;
    CheckInput(file);
    getline(file, lname);

    // Try to read job title.
    while (file.good() && file.get() != ':')
        continue;
    CheckInput(file);
    getline(file, job);
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

void employee::WriteAll(std::ofstream& file) const
{
    file << ClassKind::EMPLOYEE << std::endl;
    abstr_emp::WriteAll(file);
}

void employee::ReadAll(std::ifstream& file)
{
    abstr_emp::ReadAll(file);
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

void manager::WriteAll(std::ofstream& file) const
{
    file << ClassKind::MANAGER << std::endl;
    abstr_emp::WriteAll(file);
    file << "Number of people managed: " << inchargeof << std::endl;
}

void manager::ReadAll(std::ifstream& file)
{
    abstr_emp::ReadAll(file);

    // Try to read 'in charge of' value
    while (file.good() && file.get() != ':')
        continue;
    CheckInput(file);
    file >>inchargeof;

    file.get();
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

void fink::WriteAll(std::ofstream& file) const
{
    file << ClassKind::FINK << std::endl;
    abstr_emp::WriteAll(file);
    file << "Reports to: " << reportsto << std::endl;
}

void fink::ReadAll(std::ifstream& file)
{
    abstr_emp::ReadAll(file);

    // Try to read 'reports to' value
    while (file.good() && file.get() != ':')
        continue;
    CheckInput(file);
    getline(file, reportsto);
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

void highfink::WriteAll(std::ofstream& file) const
{
    file << ClassKind::HIGHFINK << std::endl;
    abstr_emp::WriteAll(file);
    file << "Number of people managed: " << InChargeOf() << std::endl;
    file << "Reports to: " << ReportsTo() << std::endl;
}

void highfink::ReadAll(std::ifstream& file)
{
    abstr_emp::ReadAll(file);

    // Try to read 'in charge of' value
    while (file.good() && file.get() != ':')
        continue;
    CheckInput(file);
    file >> InChargeOf();

    file.get();

    // Try to read 'reports to' value
    while (file.good() && file.get() != ':')
        continue;
    CheckInput(file);
    getline(file, ReportsTo());
}