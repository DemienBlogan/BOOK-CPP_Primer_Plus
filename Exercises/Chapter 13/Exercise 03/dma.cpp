// dma.cpp - dma class methods

#include <cstring>
#include "dma.h"

// abstractDMA methods
abstractDMA::abstractDMA(const char* l, int r)
{
	label = new char[std::strlen(l) + 1];
	std::strcpy(label, l);
	rating = r;
}

abstractDMA::abstractDMA(const abstractDMA& other)
{
	label = new char[std::strlen(other.label) + 1];
	std::strcpy(label, other.label);
	rating = other.rating;
}

abstractDMA::~abstractDMA()
{
	delete[] label;
}

abstractDMA& abstractDMA::operator=(const abstractDMA& other)
{
	if (this == &other)
		return *this;

	delete[] label;

	label = new char[std::strlen(other.label) + 1];
	std::strcpy(label, other.label);
	rating = other.rating;

	return *this;
}

void abstractDMA::View() const
{
	using std::cout;
	using std::endl;

	cout << "Label: " << label << endl;
	cout << "Rating: " << rating << endl;
}

std::ostream& operator<<(std::ostream& os, const abstractDMA& dma)
{
	os << "Label: " << dma.label << std::endl;
	os << "Rating: " << dma.rating << std::endl;
	return os;
}

// baseDMA methods
baseDMA::baseDMA(const char* l, int r)
	: abstractDMA(l, r)
{ }

baseDMA::baseDMA(const baseDMA& rs)
	: abstractDMA(rs)
{ }

baseDMA::~baseDMA()
{ }

void baseDMA::View() const
{
	using std::cout;
	using std::endl;

	cout << "baseDMA object\n";
	cout << "Label: " << GetLabel() << endl;
	cout << "Rating: " << GetRating() << endl;
}

baseDMA& baseDMA::operator=(const baseDMA& rs)
{
	abstractDMA::operator=(rs);
	return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs)
{
	os << (const abstractDMA&)rs;
	return os;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char* c, const char* l, int r)
	: abstractDMA(l, r)
{
	std::strncpy(color, c, 39);
	color[39] = '\n';
}

lacksDMA::lacksDMA(const char* c, const abstractDMA& rs)
	: abstractDMA(rs)
{
	std::strncpy(color, c, COL_LEN - 1);
	color[COL_LEN - 1] = '\n';
}

void lacksDMA::View() const
{
	using std::cout;
	using std::endl;

	cout << "lacksDMA object\n";
	abstractDMA::View();
	cout << "Color: " << color << endl;
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls)
{
	os << (const abstractDMA&)ls;
	os << "Color: " << ls.color << std::endl;
	return os;
}

// hasDMA methods
hasDMA::hasDMA(const char* s, const char* l, int r)
	: abstractDMA(l, r)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const abstractDMA& hs)
	: abstractDMA(hs)
{
	style = new char[std::strlen(s) + 1];
	std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs)
	: abstractDMA(hs)
{
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
	delete[] style;
}

void hasDMA::View() const
{
	using std::cout;
	using std::endl;

	cout << "hasDMA object" << endl;
	abstractDMA::View();
	cout << "Style: " << style << endl;
}

hasDMA& hasDMA::operator=(const hasDMA& hs)
{
	if (this == &hs)
		return *this;

	abstractDMA::operator=(hs);
	delete[] style;
	style = new char[std::strlen(hs.style) + 1];
	std::strcpy(style, hs.style);

	return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs)
{
	os << (const abstractDMA&)hs;
	os << "Style: " << hs.style << std::endl;
	return os;
}