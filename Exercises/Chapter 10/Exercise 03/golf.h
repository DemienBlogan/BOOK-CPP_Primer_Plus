#pragma once
class Golf
{
private:
	static const int Length = 40;
	char fullname[Length];
	int handicap;

public:
	Golf();
	Golf(const char* name, int hc);
	void SetHandicap(int hc);
	void Show() const;
};