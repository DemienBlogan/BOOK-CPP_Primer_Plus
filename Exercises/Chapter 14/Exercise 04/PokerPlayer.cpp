#include <iostream>
#include <cstdlib>
#include "PokerPlayer.h"

void PokerPlayer::ShowCardValue() const
{
    std::cout << "Card Value: " << cardValue << std::endl;
}

PokerPlayer::PokerPlayer()
{
    cardValue = std::rand() % 52 + 1;
}

int PokerPlayer::Draw()
{
    cardValue = std::rand() % 52 + 1;
    return cardValue;
}

void PokerPlayer::Show() const
{
    Person::Show();
    ShowCardValue();
}