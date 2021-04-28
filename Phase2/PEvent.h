#pragma once
#include "Event.h"
class MarsStation;
class PEvent : public Event
{

public:
	PEvent(int ED, int ID);
	virtual void Execute(MarsStation *Ms);
	~PEvent();
};

