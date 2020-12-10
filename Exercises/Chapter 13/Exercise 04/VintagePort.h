#include "Port.h"

class VintagePort : public Port // style necessarily = "vintage"
{
private:
	char* nickname;
	int year; 

public:
	VintagePort(const char* brand, int bottles, const char* nickname, int year);
	VintagePort(const VintagePort& other);

	~VintagePort() 
	{
		delete[] nickname;
	}

	VintagePort& operator=(const VintagePort& other);

	void Show() const;

	friend std::ostream& operator<<(std::ostream& os, const VintagePort& vintagePort);
};