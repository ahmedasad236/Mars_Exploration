#pragma once
enum M_Type { MOUNTAINOUS, POLAR, EMERGENCY };
class Rover
{
	int ID;
	int Speed;
	int CheckupDuration;
	M_Type Type;
	int NumberOfOrderServed;
public:
	Rover();
	void SetSpeed(int);
	int GetSpeed();
	void SetID(int);
	int GetID();
	void SetCheckupDuration(int);
	int GetCheckupDuration();
	void SetType(M_Type);
	M_Type GetType();
	void SetNumberOfOrderServed();
	int GetNumberOfOrderServed();
	~Rover();
};