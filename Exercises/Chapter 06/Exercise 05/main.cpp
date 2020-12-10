/*
5. The Kingdom of Neutronia, where the unit of currency is the tvarp, has the following
income tax code:

First 5,000 tvarps: 0% tax
Next 10,000 tvarps: 10% tax
Next 20,000 tvarps: 15% tax
Tvarps after 35,000: 20% tax

For example, someone earning 38,000 tvarps would owe 5,000 × 0.00 + 10,000 ×
0.10 + 20,000 × 0.15 + 3,000 × 0.20, or 4,600 tvarps.Write a program that uses a
loop to solicit incomes and to report tax owed.The loop should terminate when
the user enters a negative number or non-numeric input.
*/

#include <iostream>

using namespace std;

int main()
{
	double tvarps;

	const double FIRST_5000_TVARPS_TAX = 0.00;
	const double NEXT_10000_TVARPS_TAX = 0.10;
	const double NEXT_20000_TVARPS_TAX = 0.15;
	const double AFTER_35000_TVARPS_TAX = 0.20;

	do
	{
		cout << "Enter tvarps (or negative value or 'q' to stop): ";
		cin >> tvarps;

		if (cin && tvarps >= 0)
		{
			double tax;

			if (tvarps > 35000)
			{
				tax = 5'000 * FIRST_5000_TVARPS_TAX + 
					10'000 * NEXT_10000_TVARPS_TAX + 
					20'000 * NEXT_20000_TVARPS_TAX +
					(tvarps - 35000) * AFTER_35000_TVARPS_TAX;
			}
			else if (tvarps > 20000)
			{
				tax = 5'000 * FIRST_5000_TVARPS_TAX +
					10'000 * NEXT_10000_TVARPS_TAX +
					(tvarps - 20000) * NEXT_20000_TVARPS_TAX;
			}
			else if (tvarps > 10000)
			{
				tax = 5'000 * FIRST_5000_TVARPS_TAX +
					(tvarps - 10000) * NEXT_10000_TVARPS_TAX;
			}
			else
			{
				tax = 5'000 * FIRST_5000_TVARPS_TAX;
			}
			
			cout << "Tax = " << tax << endl;
		}

	} while (cin && tvarps >= 0);

	return 0;
}