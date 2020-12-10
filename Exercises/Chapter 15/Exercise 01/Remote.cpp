#include "Remote.h"
#include "Television.h"

Remote::Remote(int mode)
	: mode(mode), normal(true)
{ }

bool Remote::IsNormal() const
{
	return normal;
}

bool Remote::SetVolumeUp(Television& tv)
{
	return tv.SetVolumeUp();
}

bool Remote::SetVolumeDown(Television& tv) 
{
	return tv.SetVolumeDown();
}

void Remote::TurnOnOff(Television& tv) 
{
	tv.TurnOnOff();
}

void Remote::SetChannelUp(Television& tv) 
{ 
	tv.SetChannelUp();
}

void Remote::SetChannelDown(Television& tv)
{
	tv.SetChannelDown();
}

void Remote::SetMode(Television& tv) 
{ 
	tv.SetMode();
}

void Remote::SetInput(Television& tv) 
{
	tv.SetInput(); 
}

void Remote::SetChannel(Television& tv, int channel)
{ 
	tv.channel = channel;
}