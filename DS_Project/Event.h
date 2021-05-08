#pragma once
#include "Mission.h"
class MarsStation;

class Event
{
protected:
	int ED;
	int MissionID;
public:

	Event(int ED, int MID);
	virtual void Execute(MarsStation* Ms) = 0;

};