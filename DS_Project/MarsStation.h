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
	UI userInterface; // Object from UI class
	int no_EmerR, no_polarR, no_mountainousR; // 
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
	bool Exit; // boolean Expression to terminate the program
	

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
	int Mmissions; // to use it in output File 
public:

	MarsStation();
	void GetInput();//Get Input From User
	bool DeleteFromMountList(int id, Missions* &m);//Delete From Mountainous List
	void AddToEmergencyList(Missions*, float);//Add To Emergency List
	void AddToPolarList(Missions*);//Add To Polar List
	void AddToMountList(Missions*);//Add To Mountainous List
	void Simulation();//Simulation Of The Program
	void AssignToRover();//Assigning Rover To Mission
	void ExecuteEvent();//Execution Even
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
	~MarsStation();
};

