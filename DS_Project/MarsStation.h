#pragma once
#include "Event.h"
#include "Rover.h"
#include "Mission.h"
#include "Defs.h"
#include "PEvent.h"
#include "FEvent.h"
#include "CEvent.h"

using namespace std;

class MarsStation
{
private:
	Queue<Event*> EventList;
	PriorityQueue<Rover*> Emergency_Rovers;
	PriorityQueue<Rover*> Mountainous_Rovers;
	PriorityQueue<Rover*> Polar_Rovers;
	PriorityQueue<Rover*> RoversInCheckUp;
	PriorityQueue<Rover*> RoversInExecution;

	PriorityQueue<Missions*> Emergency_Missions;
	LinkedList<Missions*> Mountainous_Missions;
	Queue<Missions*> Polar_Missions;
	PriorityQueue<Missions*> MissionsInExecutions;
	Queue<Missions*> CompletedMissions;


	int CurrentStep;

public:

	MarsStation();
	void GetInput(ifstream& InputFile);
	bool DeleteFromMountList(int id, Missions* m = NULL);
	void AddToEmergencyList(Missions*, float);
	void AddToPolarList(Missions*);
	void AddToMountList(Missions*);
	void Simulation();
	void AssignToRover();

	//needed for getting information from input file
	int no_EmerR, no_polarR, no_mountainousR;
	int P_Speed, M_Speed, E_Speed;
	int Max_Mission_before_checkup;
	int P_CK, M_CK, E_CK;
	int AutoP;
	int no_events;



};

