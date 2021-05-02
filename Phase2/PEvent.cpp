#include "PEvent.h"
PEvent::PEvent(int ED, int ID) :Event(ED, ID)
{

}

void PEvent::Execute(MarsStation *Ms)
{
	Missions* tempMis = NULL;
	Ms->DeleteFromMountList(MissionID,tempMis);
	Ms->AddToEmergencyList(tempMis);
}