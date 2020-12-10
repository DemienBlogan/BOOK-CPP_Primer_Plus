/*
3. Write and test a variadic template function sum_values() that accepts an arbitrarily
long list of arguments with numeric values (they can be a mixture of types) and
returns the sum as a long double value.
*/

#include <iostream>

template <typename T, typename... Args>
long double sum_values(const T& value, const Args&... args);

template <typename T>
long double sum_values(const T& value);

int main()
{
	long double sum = sum_values(1, 2U, 3L, 3LL, 4UL, 5ULL, 6.1F, 6.2, 6.3L);
	std::cout << sum << std::endl;

	return 0;
}


template <typename T, typename... Args>
long double sum_values(const T& value, const Args&... args)
{
	return value + sum_values(args...);
}

template <typename T>
long double sum_values(const T& value)
{
	return value;
}