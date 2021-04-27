#pragma once

#include "Event.h"
#include "Defs.h"
class MarsStation;

class FEvent : public Event
{
	M_TYPE Type;  //Type of mission
	int TLoc;	//Target Location
	int ReqDays; //Required days to complete the mission
	int Sig; //significant of the mission
public:
	FEvent(M_TYPE t, int ED, int ID, int location, int days, int sig);

	virtual void Execute(MarsStation *Ms);
	virtual ~FEvent();

};
