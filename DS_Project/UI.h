#pragma once
#include "Defs.h"
#include "Mission.h"
#include "Rover.h"
using namespace std;

class UI
{

public:
	UI();
	//void GetInput(ifstream& InputFile);
	void PrintWaiting(int day, int waiting, PriorityQueue<Missions*> &E, Queue<Missions*> &P, LinkedList<Missions*> &M);
	void PrintInExecution(int inExecution, PriorityQueue<Rover*> &rovers);
	void PrintAvailableRovers(int available, PriorityQueue<Rover*> &E, PriorityQueue<Rover*> &M, PriorityQueue<Rover*> &P);
	void PrintCheckUp(int incheckup, PriorityQueue<Rover*> &check);
	void PrintCompleted(int comp, Queue<Missions*> &completed);
	int ChooseMode();
	void SlientMode(int);
	bool StepByStep();
	bool interActiveMode();

};