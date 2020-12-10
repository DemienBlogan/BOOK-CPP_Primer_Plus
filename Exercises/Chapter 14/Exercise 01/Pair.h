#pragma once

template <typename T1, typename T2>
class Pair
{
private:
	T1 value1;
	T2 value2;

public:
	Pair() = default;
	Pair(const T1& value1, const T2& value2)
		: value1(value1), value2(value2)
	{ }

	T1& first() { return value1; }
	T2& second() { return value2; }

	T1 first() const { return value1; }
	T2 second() const { return value2; }
};