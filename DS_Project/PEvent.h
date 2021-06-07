#pragma once
#include "Event.h"
#include "MarsStation.h"
class PEvent : public Event
{
public:
	PEvent(int ED, int ID);
	virtual void Execute(MarsStation* Ms);
	virtual ~PEvent();
};
