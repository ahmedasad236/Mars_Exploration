#include"Missions.h"
Missions::Missions(M_Type m)
{
	Type = m;
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
M_State Missions::getState()
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
int Missions::getLastDay(double speed,double roverTimeWork)
{
	return StartDay + (((TargetLocation / speed) * 2) / 25) + (roverTimeWork / 25);
}