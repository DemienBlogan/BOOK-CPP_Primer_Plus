#pragma once

typedef int Item;

class List
{
private:
	static const size_t SIZE = 5;
	Item items[SIZE];
	int lastIndex;

public:
	List()
		: items(), lastIndex(-1)
	{ }
	
	bool AddItem(const Item& item);
	bool IsEmpty() const { return lastIndex == -1; }
	bool IsFull() const { return lastIndex == SIZE - 1; }
	void DoForEachItem(void (*function)(Item& item));
};