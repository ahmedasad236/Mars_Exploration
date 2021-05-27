#include "CEvent.h"

CEvent::CEvent(int ED, int ID) :Event(ED, ID)
{

}

void CEvent::Execute(MarsStation* Ms)
{
	Missions* dummy = NULL;
	if (Ms->DeleteFromMountList(MissionID, dummy))
		Ms->incrementCancelled();

}
