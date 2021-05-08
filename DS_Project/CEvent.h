#pragma once
#include "Event.h"
#include"MarsStation.h"
class CEvent : public Event
{

public:
	CEvent(int ED, int ID);
	virtual void Execute(MarsStation* Ms);

};