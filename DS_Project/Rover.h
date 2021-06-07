#pragma once
#include "Defs.h"
#include "Mission.h"
class Rover
{
	int ID;
	int Speed;
	int CheckupDuration;
	int DurationDay_starting; // Start Of checkup
	int DurationDay_ending;	// End Of Checkup
	int maxMissionBeforeCheckup; 
	int NumberOfOrderServed;
	M_TYPE Type;
	Missions* myMission;
public:
	Rover();
	Rover(int id, int sp, M_TYPE t, int checkDuration, int missBefCheck);
	void SetSpeed(int);
	int GetSpeed();
	void setDurationDay_starting(int day); // Set the start of checkup
	int getDurationDay_starting();	// Get the start of checkup
	int getDurationDay_ending();  // Get the End of checkup
	void SetID(int);
	int GetID();
	void SetCheckupDuration(int);
	int GetCheckupDuration();
	void SetType(M_TYPE);
	M_TYPE GetType();
	void SetNumberOfOrderServed(int i = -1); // Set the number of missions before Checkup
	int GetNumberOfOrderServed();	//Get the number of missions before Checkup
	int GetMaxMissionBeforeCheckup(); 
	void setMission(Missions* m); 
	Missions* getMission() const;
	~Rover();
};
