/*
7. Modify Listing 8.14 so that it uses two template functions called SumArray() to
return the sum of the array contents instead of displaying the contents.The program
now should report the total number of things and the sum of all the debts.
*/

#include <iostream>

template <typename T>
double SumArray(T arr[], int n);

template <typename T>
double SumArray(T* arr[], int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;

	int things[6] = { 13, 31, 103, 301, 310, 130 };
	struct debts mr_E[3] =
	{
		{ "Ima Wolfe", 2400.0 },
		{ "Ura Foxe", 1300.0 },
		{ "Iby Stout", 1800.0 }
	};
	double* pd[3];

	for (int i = 0; i < 3; i++)
		pd[i] = &mr_E[i].amount;

	double sum1 = SumArray(things, 6);
	double sum2 = SumArray(pd, 3);

	cout << "Sum1 = " << sum1 << endl;
	cout << "Sum2 = " << sum2 << endl;

	return 0;
}

template <typename T>
double SumArray(T arr[], int n)
{
	using namespace std;

	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

template <typename T>
double SumArray(T* arr[], int n)
{
	using namespace std;

	double sum = 0;
	for (int i = 0; i < n; i++)
		sum += *arr[i];
	return sum;
}