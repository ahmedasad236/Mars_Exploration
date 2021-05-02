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
	int *arr = new int[no_ofRovers + 1];
	for (int i = 1; i <= no_ofRovers; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < no_mountainousR; i++) {
		Rover* M_ROVER = new Rover();
		M_ROVER->SetID(arr[i + 1]);
		
	}
}

bool MarsStation::DeleteFromMountList(int id)
{
	bool test = false;
	Queue<Missions*>tempM;

	Missions* tempMis;
	while (Mountainous_Missions.dequeue(tempMis) && !test)
	{
		if (id != tempMis->getID())
			tempM.enqueue(tempMis);

		else
			test = true;
	}


	while (Mountainous_Missions.dequeue(tempMis))
		tempM.enqueue(tempMis);

	while (tempM.dequeue(tempMis))
		Mountainous_Missions.enqueue(tempMis);

	return test;
}

void MarsStation::AddToEmergencyList(Missions* mis,float priority)
{
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