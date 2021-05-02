#include "PEvent.h"
PEvent::PEvent(int ED, int ID) :Event(ED, ID)
{

}

void PEvent::Execute(MarsStation *Ms)
{
	Missions* tempMis = Ms->DeleteFromMountList_WithReturn(MissionID);
	Ms->AddToEmergencyList(tempMis);
}