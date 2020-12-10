#pragma once

class Cd // represents a CD disk
{
private:
	char performers[50];
	char label[20];
	int selections;  // number of selections
	double playtime; // playing time in minutes

public:
	Cd(const char* performers, const char* label, int selections, double playtime);
	Cd(const Cd& other);
	Cd();

	virtual ~Cd();

	virtual void Report() const; // reports all CD data

	virtual Cd& operator=(const Cd& other);
};