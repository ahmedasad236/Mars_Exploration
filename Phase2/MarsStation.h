#pragma once
#include "Event.h"
#include "Rover.h"
#include "Mission.h"

using namespace std;
#include "Defs.h"
class MarsStation
{
private:
	Queue<Event*> EventList;
	Queue<Rover*> Emergency_Rovers;
	Queue<Rover*> Mountainous_Rovers;
	Queue<Rover*> Polar_Rovers;
	PriorityQueue<Rover*> RoversInCheckUp;


	PriorityQueue<Missions*> Emergency_Missions;
	Queue<Missions*> Mountainous_Missions;
	Queue<Missions*> Polar_Missions;
	PriorityQueue<Missions*> MissionsInExecutions;
	Queue<Missions*> CompletedMissions;
public:




	MarsStation();
	void GetInput();
	bool DeleteFromMountList(int id,Missions* m = NULL);
	void AddToEmergencyList(Missions*);
	void AddToPolarList(Missions*);
	void AddToMountList(Missions*);

	//needed for getting information from input file
	int no_EmerR, no_polarR, no_mountainousR;
	int P_Speed, M_Speed, E_Speed;
	int Max_Mission_before_checkup;
	int P_CK, M_CK, E_CK;
	int AutoP;
	int no_events;



};
