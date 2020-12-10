#pragma once
#include <string>
#include <valarray>
#include "Pair.h"

class Wine
{
	using ArrayInt = std::valarray<int>;
	using PairArray = Pair<ArrayInt, ArrayInt>;

private:
	std::string label;
	PairArray yearsBottles;

public:
	Wine() = default;
	Wine(const char* label, int yearsAmount, const int yearsArray[], const int bottlesArray[]);
	Wine(const char* label, int yearsAmount);

	void GetBottles();
	void Show() const;
	int sum() const;

	std::string Label() const { return label; }
};