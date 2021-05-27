#pragma once
#include "Defs.h"
#include "Mission.h"
class Rover
{
	int ID;
	int Speed;
	int CheckupDuration;
	int DurationDay_starting;
	int DurationDay_ending;
	int maxMissionBeforeCheckup;
	int NumberOfOrderServed;
	M_TYPE Type;
	Missions* myMission;
public:
	Rover();
	Rover(int id, int sp, M_TYPE t, int checkDuration, int missBefCheck);
	void SetSpeed(int);
	int GetSpeed();
	void setDurationDay_starting(int day);
	int getDurationDay_starting();
	int getDurationDay_ending();
	void SetID(int);
	int GetID();
	void SetCheckupDuration(int);
	int GetCheckupDuration();
	void SetType(M_TYPE);
	M_TYPE GetType();
	void SetNumberOfOrderServed(int i = -1);
	int GetNumberOfOrderServed();
	int GetMaxMissionBeforeCheckup();
	void setMission(Missions* m);
	Missions* getMission() const;
	~Rover();
};
