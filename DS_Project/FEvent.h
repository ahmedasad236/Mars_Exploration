#pragma once

#include "Event.h"
#include "Defs.h"
#include "MarsStation.h"
class FEvent : public Event
{
	M_TYPE Type;  //Type of mission
	int TLoc;	//Target Location
	int ReqDays; //Required days to complete the mission
	float Sig; //significant of the mission
public:
	FEvent(M_TYPE t, int ED, int ID, int location, int days, float sig);

	virtual void Execute(MarsStation* Ms);
	M_TYPE getMissionType() const;
	void setMissionType(M_TYPE t);
	virtual ~FEvent();

};