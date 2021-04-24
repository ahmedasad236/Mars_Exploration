#pragma once
#include "Event.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Rover.h"
#include "Mission.h"
#include <fstream>
#include <iostream>
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


	PriorityQueue<Mission*> Emergency_Missions;
	LinkedList<Mission*> Mountainous_Missions;
	Queue<Mission*> Polar_Missions;
	PriorityQueue<Mission*> MissionsInExecutions;
	Queue<Mission*> CompletedMissions;
public:




	MarsStation();
	void GetInput();

	//needed for getting information from input file
	int no_EmerR, no_polarR, no_mountainousR;
	int P_Speed, M_Speed, E_Speed;
	int Max_Mission_before_checkup;
	int P_CK, M_CK, E_CK;
	int AutoP;
	int no_events;


};
