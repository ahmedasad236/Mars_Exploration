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
	int StartDay; // Start of Execution
	int FD; // formulation Day
	double SpeedAssignedRover;
public:
	Missions();
	Missions(M_TYPE type, int Id, double Target, int DTF,int fd);
	void setTargetLocation(double& targetLocation);
	int getID();
	void setID(int id);
	double getTargetLocation();
	double getPriority();
	void set_state(M_STATUS m);
	void set_type(M_TYPE m);
	void setMissionDuration(double targetLocation); 
	double getMissionDuration();
	void setSignificance(int s);
	void Assign();
	void setSpeed(double);
	double getSpeed();
	int getWD(); // Get waiting Day
	int getED(); // Get the Execution duration of the mission
	void setAssignDay(int); // set the day of assignment
	int getAssignDay();

	void setFD(int fd); // set the formulation Day
	int getFD();
	
	M_STATUS getState();
	M_TYPE get_type();
	int getLastDay(); // get the completion day
	~Missions();
};

