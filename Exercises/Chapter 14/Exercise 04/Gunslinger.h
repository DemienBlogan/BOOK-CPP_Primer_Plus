#pragma once
#include "Person.h"

class Gunslinger : public virtual Person
{
private:
	int notches;
	int drawTime;

protected:
	void ShowDrawTimeAndNotches() const;

public:
	Gunslinger(const std::string& firstName = "", const std::string& lastName = "", int drawTime = 1, int notches = 6);
	
	int Draw() const { return drawTime; }

	virtual void Show() const override;
	virtual void Set() override;

	virtual ~Gunslinger() = default;
};