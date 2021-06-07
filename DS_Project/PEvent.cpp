#include "PEvent.h"
PEvent::PEvent(int ED, int ID) :Event(ED, ID)
{

}

void PEvent::Execute(MarsStation* Ms)
{
	Missions* temp = NULL;
	
	Ms->DeleteFromMountList(MissionID, temp);
	
	if (temp)
	{
		temp->set_type(EMERGENCY);
		Ms->AddToEmergencyList(temp, temp->getPriority());
	}
}

PEvent::~PEvent()
{
}
