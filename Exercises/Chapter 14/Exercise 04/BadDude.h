#pragma once
#include "Gunslinger.h"
#include "PokerPlayer.h"

class BadDude final : public Gunslinger, public PokerPlayer
{
public:
	BadDude(const std::string& firstName = "", const std::string& lastName = "", int drawTime = 1, int notches = 6);

	int GDraw() const { return Gunslinger::Draw(); }
	int CDraw() { return PokerPlayer::Draw(); }
	
	virtual void Show() const override;
	virtual void Set() override;

	virtual ~BadDude() = default;
};