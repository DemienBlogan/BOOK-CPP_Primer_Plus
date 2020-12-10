#pragma once

class Television;

class Remote
{
private:
	int mode;
	bool normal;

public:
	enum State { OFF, ON };
	enum { MIN_VALUE, MAX_VALUE = 20 };
	enum { ANTENNA, CABLE };
	enum { TV, DVD };

	Remote(int mode = TV);

	bool IsNormal() const;
	bool SetVolumeUp(Television& tv);
	bool SetVolumeDown(Television& tv);
	void TurnOnOff(Television& tv);
	void SetChannelUp(Television& tv);
	void SetChannelDown(Television& tv);
	void SetMode(Television& tv);
	void SetInput(Television& tv);
	void SetChannel(Television& tv, int channel);

	friend Television;
};