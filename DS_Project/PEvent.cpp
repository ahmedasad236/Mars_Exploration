#include "PEvent.h"
PEvent::PEvent(int ED, int ID) :Event(ED, ID)
{

}

void PEvent::Execute(MarsStation* Ms)
{
	Missions* temp = NULL;
	Ms->DeleteFromMountList(MissionID, temp);
	Ms->AddToEmergencyList(temp, temp->getPriority());
}