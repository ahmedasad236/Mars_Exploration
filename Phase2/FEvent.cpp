#include "FEvent.h"

FEvent::FEvent(M_TYPE t, int ED, int ID, int location, int days, int sig) :Event(ED, ID)
{
	TLoc = location;
	ReqDays = days;
	Sig = sig;
	Type = t;
}

void FEvent::Execute(MarsStation *Ms)
{
	
	


}