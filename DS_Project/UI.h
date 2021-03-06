#pragma once
#include "Defs.h"
#include "Mission.h"
#include "Rover.h"
using namespace std;

class UI
{
	// Utility Functions to color the Output
	string Color(int color = 7, string Message = "") {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		return Message;
	}

	int Color(int color, int num) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		return num;
	}

	string in_out_file_num; // The input/output file number 

public:
	UI();
	void PrintWaiting(int day, int waiting, PriorityQueue<Missions*> &E, Queue<Missions*> &P, LinkedList<Missions*> &M);
	void PrintInExecution(int inExecution, PriorityQueue<Rover*> &rovers);
	void PrintAvailableRovers(int available, PriorityQueue<Rover*> &E, PriorityQueue<Rover*> &M, PriorityQueue<Rover*> &P);
	void PrintCheckUp(int incheckup, PriorityQueue<Rover*> &check);
	void PrintCompleted(int comp, Queue<Missions*> &completed);
	int ChooseMode();
	void SlientMode(int);
	bool StepByStep();
	bool interActiveMode();
	void PrintFailer(M_TYPE type);
	void EnterFileName();
	string getOutInFileNum();

};