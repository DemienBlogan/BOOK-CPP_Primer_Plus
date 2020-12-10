#include "List.h"

bool List::AddItem(const Item& item)
{
	if (IsFull())
		return false;

	items[++lastIndex] = item;

	return true;
}

void List::DoForEachItem(void(*function)(Item& item))
{
	if (IsEmpty())
		return;

	for (int i = 0; i <= lastIndex; i++)
		function(items[i]);
}