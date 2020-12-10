#include "BadDude.h"

BadDude::BadDude(const std::string& firstName, const std::string& lastName, int drawTime, int notches)
	: Gunslinger(firstName, lastName, drawTime, notches), PokerPlayer()
{ }

void BadDude::Show() const
{
	Gunslinger::Show();
	PokerPlayer::ShowCardValue();
}

void BadDude::Set()
{
	Gunslinger::Set();
}