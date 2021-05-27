#include "Mission.h"
Missions::Missions()
{
	ID = -1;

}

Missions::Missions(M_TYPE type, int Id, double Target, int DTF , int fd)
{
	ID = Id;
	TargetLocation = Target;
	MissionDuration = DTF;
	Type = type;
	Assigned = false;
	StartDay = -1;
	State = WAITING;
	FD = fd;
}
void Missions::setTargetLocation(double& targetLocation)
{
	TargetLocation = targetLocation;
}
int Missions::getID()
{
	return ID;
}
void Missions::setID(int id)
{
	ID = id;
}
double Missions::getTargetLocation()
{
	return TargetLocation;
}
void Missions::ToEmergency()
{
	Type = EMERGENCY;
}
double Missions::getPriority()
{
	return getFactorOfImportance();
}
void Missions::set_state(M_STATUS m)
{
	State = m;
}
void Missions::set_type(M_TYPE m)
{
	Type = m;
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
	double factor = 0.0;
	/////////////////////////////
	//operations to calc the factor
	factor = 1000 * Significance - 100 * FD - 0.1 * TargetLocation; 
	/////////////////////////////
	// 5000 - 200 - 5 = 4795;
	// 4796
	// 8795
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

void Missions::setSpeed(double s)
{
	SpeedAssignedRover = s;
}
double Missions::getSpeed()
{
	return SpeedAssignedRover;
}
int Missions::getWD()
{
	return StartDay - FD;
}
int Missions::getED()
{
	return getLastDay() - StartDay;
}
void Missions::setAssignDay(int d)
{
	StartDay = d;
}
int Missions::getAssignDay()
{
	return StartDay;
}
void Missions::setFD(int fd)
{
	FD = fd;
}
int Missions::getFD()
{
	return FD;
}
M_STATUS Missions::getState()
{
	return State;
}

M_TYPE Missions::get_type()
{
	return Type;
}
int Missions::getLastDay()
{
	return StartDay + ceil(( (TargetLocation / SpeedAssignedRover) * 2) / 25) + (MissionDuration);
}
