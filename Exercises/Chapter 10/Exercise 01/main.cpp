/*
1. Provide method definitions for the class described in Chapter Review Question 5
   and write a short program that illustrates all the features.
*/

#include "BankAccount.h"

int main()
{
	BankAccount account{ "Demien Blogan", "1881-1881", 20000.00 };

	account.Show();
	account.Deposite(520);
	account.Show();
	account.Withdraw(2000);
	account.Show();

	return 0;
}