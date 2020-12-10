#pragma once

class Cow 
{
	char name[20];
	char* hobby;
	double weight;
public:
	Cow();
	Cow(const char* name, const char* hobby, double weight);
	Cow(const Cow& otherCow);
	~Cow();
	Cow& operator=(const Cow& otherCow);
	void ShowCow() const;
};