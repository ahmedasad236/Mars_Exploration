#pragma once
#include "Event.h"
#include "Rover.h"
#include "Mission.h"
#include "Defs.h"
#include "PEvent.h"
#include "FEvent.h"
#include "CEvent.h"
#include "UI.h"
using namespace std;

class MarsStation
{
private:
	UI userInterface;
	int no_EmerR, no_polarR, no_mountainousR;
	int Max_Mission_before_checkup;
	int P_CK, M_CK, E_CK;
	int AutoP;
	int no_events;
	int formulated;
	int cancelled;
	int WaitingM;
	int InExecution;
	int Rovers;
	int CheckupRovers;
	int CompletedM;
	int UImode;

	Queue<Event*> EventList;
	PriorityQueue<Rover*> Emergency_Rovers;
	PriorityQueue<Rover*> Mountainous_Rovers;
	PriorityQueue<Rover*> Polar_Rovers;
	PriorityQueue<Rover*> RoversInCheckUp;
	PriorityQueue<Rover*> RoversInExecution;
	PriorityQueue<Missions*> Emergency_Missions;
	LinkedList<Missions*> Mountainous_Missions;
	Queue<Missions*> Polar_Missions;
	Queue<Missions*> CompletedMissions;

	int countAutoPromotion;
	int CurrentStep;
public:

	MarsStation();
	void GetInput();
	bool DeleteFromMountList(int id, Missions* &m);
	void AddToEmergencyList(Missions*, float);
	void AddToPolarList(Missions*);
	void AddToMountList(Missions*);
	void Simulation();
	void AssignToRover();
	void ExecuteEvent();
	void endCheckUp();
	bool startCheckUp(Rover* myRover);
	void checkCompleted();
	void dayDetails();
	void AddToPolarRover(Rover* P);
	void AddToMountRover(Rover* M);
	void AddToEmerRover(Rover* E);
	void printDay();
	void AutoPromote();
	// Increment Auto Promoted to use it in Output File
	void incrementAutoP();

	// Increment Cancelled to use it in Output File
	void incrementCancelled();

	//needed for getting information from input File
	int getCountAutoPromotion();
	void outputFile();

};

