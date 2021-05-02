#include "MarsStation.h"
#include <fstream>
MarsStation::MarsStation()
{
}

void MarsStation::GetInput()
{
	ifstream InputFile;
	InputFile >> no_mountainousR >> no_polarR >> no_EmerR;
	//getting the total number 
	int no_ofRovers = no_EmerR + no_mountainousR + no_polarR;
	InputFile >> M_Speed >> P_Speed >> E_Speed;
	InputFile >> Max_Mission_before_checkup;
	//Reading Checkup Duration
	InputFile >> M_CK >> P_CK >> E_CK;
	//AutoP
	InputFile >> AutoP;
	//array of sequenced IDs

	int id = 0;
	
	for (int i = 0; i < no_mountainousR; i++) {
		Rover* M_ROVER = new Rover(++id, M_Speed, MOUNTAINOUS, M_CK, Max_Mission_before_checkup);
		Mountainous_Rovers.enqueue(M_ROVER);
	}
	
	for (int i = 0; i < no_polarR; i++) {
		Rover* P_ROVER = new Rover(++id, P_Speed, POLAR, P_CK, Max_Mission_before_checkup);
		Polar_Rovers.enqueue(P_ROVER);
	}

	for (int i = 0; i < no_EmerR; i++) {
		Rover* E_ROVER = new Rover(++id, E_Speed, EMERGENCY, E_CK, Max_Mission_before_checkup);
		Emergency_Rovers.enqueue(E_ROVER);
	}

}

bool MarsStation::DeleteFromMountList(int id,Missions* m)
{
	bool test = false;
	Queue<Missions*>tempM;

	Missions* tempMis;
	while (Mountainous_Missions.dequeue(tempMis) && !test)
	{
		if (id != tempMis->getID())
			tempM.enqueue(tempMis);

		else
		{
			test = true;
			m = tempMis;
			break;
		}
	}


	while (Mountainous_Missions.dequeue(tempMis))
		tempM.enqueue(tempMis);

	while (tempM.dequeue(tempMis))
		Mountainous_Missions.enqueue(tempMis);
	
	if (!test)m = NULL;
	return test;
}


void MarsStation::AddToEmergencyList(Missions* mis)
{
	double priority = mis->getPriority();
	Emergency_Missions.enqueue(mis, priority);
}

void MarsStation::AddToPolarList(Missions* pM)
{
	Polar_Missions.enqueue(pM);
}

void MarsStation::AddToMountList(Missions* mM)
{
	Mountainous_Missions.enqueue(mM);
}
