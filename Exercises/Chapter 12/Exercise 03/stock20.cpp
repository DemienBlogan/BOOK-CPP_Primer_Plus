// stock20.cpp -- augmented version

#include <iostream>
#include <cstring>

#include "stock20.h"

// constructors
Stock::Stock() // default constructor
{
	size_t length = strlen("no name") + 1;
	company = new char[length];
	strcpy_s(company, length, "no name");

	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

Stock::Stock(const char* co, long n, double pr)
	: company(nullptr)
{
	if (co != nullptr)
	{
		size_t length = strlen(co) + 1;
		company = new char[length];
		strcpy_s(company, length, co);
	}

	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; ";
		std::cout << company << " shares set to 0.\n";

		shares = 0;
	}
	else
		shares = n;

	share_val = pr;

	set_tot();
}

// class destructor
Stock::~Stock()
{
	delete[] company;
	company = nullptr;
}

// other methods
void Stock::acquire(const char* co, long n, double pr)
{
	delete[] company;
	company = nullptr;

	if (co != nullptr)
	{
		size_t length = strlen(co) + 1;
		company = new char[length];
		strcpy_s(company, length, co);
	}

	if (n < 0)
	{
		std::cout << "Number of shares can't be negative; ";
		std::cout << company << " shares set to 0.\n";

		shares = 0;
	}
	else
		shares = n;

	share_val = pr;

	set_tot();
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		std::cout << "Number of shares purchased can't be negative.";
		std::cout << "Transaction is aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;

		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	using std::cout;

	if (num < 0)
	{
		cout << "Number of shares sold can't be negative. ";
		cout << "Transaction is aborted.\n";
	}
	else if (num > shares)
	{
		cout << "You can't sell more than you have! ";
		cout << "Transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;

		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;

	set_tot();
}

const Stock& Stock::topval(const Stock& s) const
{
	if (s.total_val > total_val)
		return s;
	else
		return *this;
}

ostream& operator<<(ostream& out, const Stock& s)
{
	using std::ios_base;

	// set format to #.###
	ios_base::fmtflags orig = out.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = out.precision(3);

	out << "Company: " << s.company;
	out << "  Shares: " << s.shares << '\n';
	out << "  Share Price: $" << s.share_val;

	// set format to #.##
	out.precision(2);
	out << "  Total Worth: $" << s.total_val << '\n';

	// restore original format
	out.setf(orig, ios_base::floatfield);
	out.precision(prec);

	return out;
}