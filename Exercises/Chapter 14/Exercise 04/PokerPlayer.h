#pragma once
#include "Person.h"

class PokerPlayer : public virtual Person
{
private:
	int cardValue;

protected:
	void ShowCardValue() const;

public:
	PokerPlayer();

	int Draw();

	virtual void Show() const override;

	virtual ~PokerPlayer() = default;
};