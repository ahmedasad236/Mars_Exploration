#pragma once
#include "Defs.h"
class Rover
{
	int ID;
	int Speed;
	int CheckupDuration;
	int maxMissionBeforeCheckup;
	M_TYPE Type;
	int NumberOfOrderServed;
public:
	Rover();
	Rover(int id, int sp, M_TYPE t, int checkDuration, int missBefCheck);
	void SetSpeed(int);
	int GetSpeed();
	void SetID(int);
	int GetID();
	void SetCheckupDuration(int);
	int GetCheckupDuration();
	void SetType(M_TYPE);
	M_TYPE GetType();
	void SetNumberOfOrderServed();
	int GetNumberOfOrderServed();
	~Rover();
};
