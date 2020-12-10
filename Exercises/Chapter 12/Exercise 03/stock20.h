// stock20.h -- augmented version

#ifndef STOCK20_H_
#define STOCK20_H_

#include <iostream>

using std::ostream;

class Stock
{
private:
	char* company;
	long shares;
	double share_val;
	double total_val;

	void set_tot() { total_val = shares * share_val; }

public:
	Stock();  // default constructor
	Stock(const char* co, long n = 0, double pr = 0.0);

	~Stock(); // do-nothing destructor

	void acquire(const char* co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	const Stock& topval(const Stock& s) const;

	friend ostream& operator<<(ostream& out, const Stock& s);
};

#endif