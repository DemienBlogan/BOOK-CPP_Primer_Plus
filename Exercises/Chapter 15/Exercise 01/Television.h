#pragma once
#include "Remote.h"

class Television
{
private:
	int state;
	int volume;
	int maxchannel;
	int channel;
	int mode;
	int input;

public:
	enum State { OFF, ON };
	enum { MIN_VALUE, MAX_VALUE = 20 };
	enum { ANTENNA, CABLE };
	enum { TV, DVD };

	Television(int s = OFF, int mc = 125);

	void TurnOnOff();
	bool IsTurnedOn() const;
	bool SetVolumeUp();
	bool SetVolumeDown();
	void SetChannelUp();
	void SetChannelDown();
	void SetMode();
	void SetInput();
	void ShowSettings() const;
	void ChangeRemoteNormalMode(Remote& remote);

	friend Remote;
};