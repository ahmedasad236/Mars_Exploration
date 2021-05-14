#include "Rover.h"

Rover::Rover()
{
	NumberOfOrderServed = 0;
}
Rover::Rover(int id, int sp, M_TYPE t, int checkDuration, int missBefCheck)
{
	ID = id;
	Speed = sp;
	Type = t;
	CheckupDuration = checkDuration;
	maxMissionBeforeCheckup = missBefCheck;
	NumberOfOrderServed = 0;
}
void Rover::SetID(int i)
{
	ID = i;
}
int Rover::GetID()
{
	return ID;
}
void Rover::SetSpeed(int i)
{
	Speed = i;
}
int Rover::GetSpeed()
{
	return Speed;
}
void Rover::setDurationDay_starting(int day)
{
	DurationDay_starting = day;
}
int Rover::getDurationDay_starting()
{
	return DurationDay_starting;
}
int Rover::getDurationDay_ending()
{
	return DurationDay_starting + CheckupDuration;
}
void Rover::SetCheckupDuration(int i)
{
	CheckupDuration = i;
}
int Rover::GetCheckupDuration()
{
	return CheckupDuration;
}
void Rover::SetType(M_TYPE i)
{
	Type = i;
}
M_TYPE Rover::GetType()
{
	return Type;
}
void Rover::SetNumberOfOrderServed()
{
	NumberOfOrderServed++;
}
int Rover::GetNumberOfOrderServed()
{
	return NumberOfOrderServed;
}
int Rover::GetMaxMissionBeforeCheckup()
{
	return maxMissionBeforeCheckup;
}
Rover::~Rover()
{
}
