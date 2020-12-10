#include "stack.h"

Stack::Stack(int n)
	: pitems(nullptr), size(0), top(0)
{
	if (n <= 0)
		return;

	size = n;
	pitems = new Item[size];
}

Stack::Stack(const Stack& st)
	: pitems(nullptr), size(st.size), top(st.top)
{
	if (st.pitems != nullptr)
	{
		pitems = new Item[size];

		for (size_t i = 0; i < size; i++)
			pitems[i] = st.pitems[i];
	}
}

Stack::~Stack()
{
	delete[] pitems;
	pitems = nullptr;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == size;
}

bool Stack::push(const Item& item)
{
	if (isfull())
		return false;

	pitems[top++] = item;

	return true;
}

bool Stack::pop(Item& item)
{
	if (isempty())
		return false;

	item = pitems[--top];

	return true;
}

Stack& Stack::operator=(const Stack& st)
{
	if (this != &st)
	{
		delete[] pitems;

		size = st.size;
		top = st.top;
		pitems = nullptr;

		if (st.pitems != nullptr)
		{
			pitems = new Item[size];

			for (size_t i = 0; i < size; i++)
				pitems[i] = st.pitems[i];
		}
	}

	return *this;
}