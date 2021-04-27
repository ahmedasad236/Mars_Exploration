#include "Mission.h"
Missions::Missions(M_TYPE type, int Id, double Target, int DTF)
{
	ID = Id;
	TargetLocation = Target;
	MissionDuration = DTF;
	Type = type;
	Assigned = false;
	StartDay = -1;
	State = WAITING;
}
void Missions::setTargetLocation(double& targetLocation)
{
	TargetLocation = targetLocation;
}
double Missions::getTargetLocation()
{
	return TargetLocation;
}
void Missions::ToEmergency()
{
	Type = EMERGENCY;
}
void Missions::set_state(M_STATUS m)
{
	State = m;
}
void Missions::setMissionDuration(double& missionDuration)
{
	MissionDuration = missionDuration;
}
double Missions::getMissionDuration()
{
	return MissionDuration;
}
void Missions::setSignificance(int s)
{
	Significance = s;
}
double Missions::getFactorOfImportance()
{
	double factor = Significance;
	/////////////////////////////
									//operations to calc the factor
	/////////////////////////////
	return factor;
}
void Missions::Assign()
{
	Assigned = true;
}

void Missions::InExecution()
{
	State = IN_EXCUTION;
}
void Missions::Completed()
{
	State = COMPLETED;
}
M_STATUS Missions::getState()
{
	return State;
}
void Missions::setStartDay(int d)
{
	StartDay = d;
}
int Missions::getStartDay()
{
	return StartDay;
}
M_TYPE Missions::get_type()
{
	return Type;
}
int Missions::getLastDay(double speed, double roverTimeWork)
{
	return StartDay + (((TargetLocation / speed) * 2) / 25) + (roverTimeWork / 25);
}