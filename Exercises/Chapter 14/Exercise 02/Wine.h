#pragma once
#include <string>
#include <valarray>
#include "Pair.h"

using ArrayInt = std::valarray<int>;
using PairArray = Pair<ArrayInt, ArrayInt>;

class Wine : private std::string, private PairArray
{
public:
	Wine() = default;
	Wine(const char* label, int yearsAmount, const int yearsArray[], const int bottlesArray[]);
	Wine(const char* label, int yearsAmount);

	void GetBottles();
	void Show() const;
	int sum() const;

	std::string Label() const { return std::string(*this); }
};