#pragma once
#include "Cd.h"

class classic : public Cd
{
private:
	char* primaryWork;

public:
	classic();
	classic(const char* primaryWork, const char* performers, const char* label, int selections, double playtime);
	classic(const classic& other);

	virtual ~classic();

	virtual void Report() const override;

	virtual classic& operator=(const classic& other);
};