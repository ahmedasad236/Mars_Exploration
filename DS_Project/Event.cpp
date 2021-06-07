#include "Event.h"

Event::Event(int ED, int MID):ED(ED), MissionID(MID)
{
}

void Event::setEventDay(int d)
{
	ED = d;
}

int Event::getEventDay() const
{
	return ED;
}

Event::~Event()
{
}
