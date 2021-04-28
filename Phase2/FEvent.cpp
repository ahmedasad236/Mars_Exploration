#include "FEvent.h"

FEvent::FEvent(M_TYPE t, int ED, int ID, int location, int days, float sig) :Event(ED, ID)
{
	TLoc = location;
	ReqDays = days;
	Sig = sig;
	Type = t;
}

void FEvent::Execute(MarsStation *Ms)
{
	Missions* A = new Missions(Type, MissionID, TLoc, ReqDays);
		switch (Type)
		{
		case(MOUNTAINOUS):
			Ms->ADDTOMLIST(A);
			break;
		case(POLAR):
			Ms->ADDTOPLIST(A);
			break;
		case(EMERGENCY):
			Ms->ADDTOELIST(A,Sig);
			break;
		default:
			break;
		}


}

FEvent::~FEvent()
{

}