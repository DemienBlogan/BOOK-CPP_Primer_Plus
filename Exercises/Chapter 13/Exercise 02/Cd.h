#pragma once

class Cd
{
private:
	char* performers;
	char* label;
	int selections;
	double playtime;

public:
	Cd(const char* performers, const char* label, int selections, double playtime);
	Cd(const Cd& other);
	Cd();

	virtual ~Cd();

	virtual void Report() const;

	virtual Cd& operator=(const Cd& other);
};