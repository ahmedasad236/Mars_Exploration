#pragma once
class Event
{
protected:
	int ED;
	int MissionID;
public:
	Event(int ED, int MID) :ED(ED), MissionID(MID)
	{}

	virtual void Execute() = 0;
	virtual ~Event()=0;
};

