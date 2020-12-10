#pragma once

#include <string>

using std::string;

class BankAccount
{
private:
	string m_depositorName;
	string m_accountNumber;
	double m_balance;

public:
	BankAccount(const string depositorName, string accountNumber, double balance);
	void Show() const;
	void Deposite(double money);
	void Withdraw(double money);
};