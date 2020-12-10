#pragma once

#include <iostream>

using std::ostream;
using std::istream;

class String
{
private:
	char* str;                    // pointer to string
	int len;                      // length of string

	static int num_strings;       // number of objects
	static const int CINLIM = 80; // cin input limit

public:
	// constructors and other methods
	String(const char* s); // constuctor
	String();              // default constructor
	String(const String&); // copy constructor
	~String();             // destructor

	int length() const { return len; }
	void stringlow();
	void stringup();
	int has(char ch) const;

	// overloaded operator methods
	String& operator=(const String& other);
	String& operator=(const char* other);
	char& operator[](int i);
	const char& operator[](int i) const;

	// overloaded operator friends
	friend String operator+(const String& str1, const String & str2);
	friend String operator+(const char* str1, const String& str2);
	friend String operator+(const String& str1, const char* str2);
	friend bool operator<(const String& st, const String& st2);
	friend bool operator>(const String& st, const String& st2);
	friend bool operator==(const String& st, const String& st2);
	friend ostream& operator<<(ostream& os, const String& st);
	friend istream& operator>>(istream& is, String& st);

	// static function
	static int HowMany();
};