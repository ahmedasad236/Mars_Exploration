#include "FEvent.h"


FEvent::FEvent(M_TYPE t, int ED, int ID, int location, int days, float sig) :Event(ED, ID)
{
	TLoc = location;
	ReqDays = days;
	Sig = sig;
	Type = t;
}

void FEvent::Execute(MarsStation* Ms)
{
	Missions* A = new Missions(Type, MissionID, TLoc, ReqDays ,ED);
	A->setSignificance(Sig);

	switch (Type)
	{
	case(MOUNTAINOUS):
		Ms->AddToMountList(A);
		break;
	case(POLAR):
		Ms->AddToPolarList(A);

		break;
	case(EMERGENCY):
		Ms->AddToEmergencyList(A, A->getPriority());
		break;
	default:
		break;
	}
}

M_TYPE FEvent::getMissionType() const
{
	return Type;
}

void FEvent::setMissionType(M_TYPE t)
{
	Type = t;
}

FEvent::~FEvent()
{
}
