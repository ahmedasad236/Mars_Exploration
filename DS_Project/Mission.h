#pragma once
#include "Defs.h"
class Missions
{
	M_TYPE Type;
	double TargetLocation;
	double MissionDuration;
	int Significance;
	bool Assigned;
	int ID;
	M_STATUS State;
	int StartDay;
public:
	Missions();
	Missions(M_TYPE type, int Id, double Target, int DTF);
	void setTargetLocation(double& targetLocation);
	int getID();
	double getTargetLocation();
	void ToEmergency();
	double getPriority();
	void set_state(M_STATUS m);
	void setMissionDuration(double& targetLocation);
	double getMissionDuration();
	void setSignificance(int s);
	double getFactorOfImportance();
	void Assign();
	void InExecution();
	void Completed();
	M_STATUS getState();
	void setStartDay(int);
	int getStartDay();
	M_TYPE get_type();
	int getLastDay(double, double);
};

