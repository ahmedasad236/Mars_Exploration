#pragma once
#include "Defs.h"
#include "LinkedList.h"
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
	Missions(M_TYPE type,int Id,double Target, int DTF);
	void setTargetLocation(double& targetLocation);
	double getTargetLocation();
	void ToEmergency();
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
template<class T>
int postionOfId(LinkedList<T>l,int i)
{
	Node<T>temp = l.Head;
	int count = 0;
	while (temp != NULL)
	{
		count++;
		if (temp->getItem().id == i)
		{
			break;
		}
		temp = temp->getNext();
	}
	if (temp == NULL)
	{
		return -1;
	}
	return count;
}