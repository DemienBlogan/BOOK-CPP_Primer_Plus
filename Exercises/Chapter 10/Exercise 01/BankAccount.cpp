#include <iostream>
#include "BankAccount.h"

using std::cout;
using std::endl;

BankAccount::BankAccount(const string depositorName, string accountNumber, double balance)
{
	m_depositorName = depositorName;
	m_accountNumber = accountNumber;
	m_balance = balance >= 0 ? balance : 0;
}

void BankAccount::Show() const
{
	cout << "Depositor's name: " << m_depositorName << endl;
	cout << "Account number:   " << m_accountNumber << endl;
	cout << "Balance: $" << m_balance << "\n\n";
}

void BankAccount::Deposite(double money)
{
	if (money > 0)
		m_balance += money;
}

void BankAccount::Withdraw(double money)
{
	if (money > 0) 
	{
		if (m_balance - money >= 0)
			m_balance -= money;
		else
			m_balance = 0;
	}
}