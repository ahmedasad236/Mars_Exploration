#pragma once
#include "Mission.h"
class Event
{
protected:
	int ED;
	int MissionID;
public:
	Event(int ED, int MID) :ED(ED), MissionID(MID)
	{}

	virtual void Execute() = 0;
};

