/*
3. Here is a structure declaration:
struct box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

a. Write a function that passes a box structure by value and that displays the
value of each member.

b. Write a function that passes the address of a box structure and that sets the
volume member to the product of the other three dimensions.

c. Write a simple program that uses these two functions.
*/

#include <iostream>

using namespace std;

struct Box
{
	char maker[40];
	float height;
	float width;
	float length;
	float volume;
};

void Show(Box box);
void SetVolume(Box* box);

int main()
{
	Box box = { "Some maker", 2.3, 5.6, 3.1 };

	SetVolume(&box);
	Show(box);

	return 0;
}

void Show(Box box)
{
	cout << "Maker: " << box.maker << endl;
	cout << "Height: " << box.height << endl;
	cout << "Width: " << box.width << endl;
	cout << "Length: " << box.length << endl;
	cout << "Volume: " << box.volume << endl;
}

void SetVolume(Box* box)
{
	box->volume = box->height * box->length * box->width;
}