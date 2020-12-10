#pragma once

class Plorg
{
private:
	static const size_t LENGTH = 20;
	char m_name[LENGTH];
	int m_ci;

public:
	Plorg(const char* name = "Plorga");
	void ChangeCI(int ci);
	void Report() const;
};