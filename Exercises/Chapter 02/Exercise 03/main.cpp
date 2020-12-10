/*
3. Write a C++ program that uses three user-defined functions (counting main() as
one) and produces the following output:

Three blind mice
Three blind mice
See how they run
See how they run

One function, called two times, should produce the first two lines, and the remaining
function, also called twice, should produce the remaining output.
*/

#include <iostream>

void Function1();
void Function2();

int main()
{
	Function1();
	Function1();
	Function2();
	Function2();	

	return 0;
}

void Function1()
{
	using namespace std;
	cout << "Three blind mice\n";

}

void Function2()
{
	using namespace std;
	cout << "See how they run\n";
}