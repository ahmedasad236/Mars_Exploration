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

void MarsStation::ADDTOMLIST(Missions * M)
{
	Mountainous_Missions.InsertEnd(M);
}
