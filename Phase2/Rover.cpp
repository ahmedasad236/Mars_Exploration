#include "Rover.h"

Rover::Rover()
{
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
Rover::~Rover()
{
}
