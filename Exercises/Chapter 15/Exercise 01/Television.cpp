#include <iostream>
#include "Television.h"

Television::Television(int state, int maxchannel)
	: state(state), volume(5), maxchannel(maxchannel), channel(2), mode(CABLE), input(TV)
{ }

void Television::TurnOnOff()
{
	state = (state == ON) ? OFF : ON;
}

bool Television::IsTurnedOn() const
{
	return state == ON;
}

bool Television::SetVolumeUp()
{
	if (volume < MAX_VALUE)
	{
		volume++;
		return true;
	}

	return false;
}

bool Television::SetVolumeDown()
{
	if (volume > MIN_VALUE)
	{
		volume--;
		return true;
	}

	return false;
}

void Television::SetChannelUp()
{
	channel = channel < maxchannel ? channel + 1 : 1;
}

void Television::SetChannelDown()
{
	channel = channel > 1 ? channel - 1 : maxchannel;
}

void Television::SetMode()
{
	mode = (mode == ANTENNA) ? CABLE : ANTENNA;
}

void Television::SetInput()
{
	input = (input == TV) ? DVD : TV;
}

void Television::ShowSettings() const
{
	std::cout << "TV is " << (state == OFF ? "Off" : "On") << std::endl;

	if (state == ON)
	{
		std::cout << "Volume setting = " << volume << std::endl;
		std::cout << "Channel setting = " << channel << std::endl;
		std::cout << "Mode = " << (mode == ANTENNA ? "antenna" : "cable") << std::endl;
		std::cout << "Input = " << (input == TV ? "TV" : "DVD") << std::endl;
	}
}

void Television::ChangeRemoteNormalMode(Remote& remote)
{
	if (state == ON)
		remote.normal = !remote.normal;
}