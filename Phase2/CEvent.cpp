#include "CEvent.h"

CEvent::CEvent(int ED, int ID) :Event(ED, ID)
{

}

void CEvent::Execute(MarsStation* Ms)
{
	Ms->DeleteFromMountList(MissionID);
}
