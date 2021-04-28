#pragma once
#include "Event.h"
class MarsStation;
class CEvent : public Event
{

public:
	CEvent(int ED, int ID);
	virtual void Execute(MarsStation *Ms);
	~CEvent();
};
