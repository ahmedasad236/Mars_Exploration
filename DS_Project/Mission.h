#pragma once
#include "Defs.h"
class Missions
{
	M_TYPE Type;
	double TargetLocation;
	double MissionDuration;
	int formulationDay;
	int Significance;
	bool Assigned;
	int ID;
	M_STATUS State;
	int StartDay;
	int FD;
	double SpeedAssignedRover;
public:
	Missions();
	Missions(M_TYPE type, int Id, double Target, int DTF);
	Missions(M_TYPE type, int Id, double Target, int DTF,int fd);
	void setTargetLocation(double& targetLocation);
	int getID();
	void setID(int id);
	double getTargetLocation();
	void ToEmergency();
	double getPriority();
	void set_state(M_STATUS m);
	void set_type(M_TYPE m);
	void setMissionDuration(double& targetLocation);
	double getMissionDuration();
	void setSignificance(int s);
	double getFactorOfImportance();
	void Assign();
	void InExecution();
	void Completed();
	void setSpeed(double);
	double getSpeed();
	int getWD();
	int getED();
	void setAssignDay(int);
	int getAssignDay();

	void setFD(int fd);
	int getFD();
	
	M_STATUS getState();
	M_TYPE get_type();
	int getLastDay();
};

