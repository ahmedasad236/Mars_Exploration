#include "MarsStation.h"
#include <fstream>
MarsStation::MarsStation()
{
	CurrentStep = 0;
}

void MarsStation::GetInput(ifstream& InputFile)
{
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
		Mountainous_Rovers.enqueue(M_ROVER, M_ROVER->GetSpeed());
	}

	for (int i = 0; i < no_polarR; i++) {
		Rover* P_ROVER = new Rover(++id, P_Speed, POLAR, P_CK, Max_Mission_before_checkup);
		Polar_Rovers.enqueue(P_ROVER, P_ROVER->GetSpeed());
	}

	for (int i = 0; i < no_EmerR; i++) {
		Rover* E_ROVER = new Rover(++id, E_Speed, EMERGENCY, E_CK, Max_Mission_before_checkup);
		Emergency_Rovers.enqueue(E_ROVER, E_ROVER->GetSpeed());
	}
	InputFile >> no_events;
	char Event_Type;
	char typeOFmission;
	int ED;
	int M_ID;
	int TLOC;
	int MDUR;
	int SIG;
	for (int i = 0; i < no_events; i++) {
		InputFile >> Event_Type;
		Event* E;
		if (Event_Type == 'F') {
			InputFile >> typeOFmission;
			InputFile >> ED;
			InputFile >> M_ID;
			InputFile >> TLOC;
			InputFile >> MDUR;
			InputFile >> SIG;
			if (typeOFmission == 'M') {
				//FEvent(M_TYPE t, int ED, int ID, int location, int days, int sig);

				E = new FEvent(MOUNTAINOUS, ED, M_ID, TLOC, MDUR, SIG);
			}
			else if (typeOFmission == 'P') {
				E = new FEvent(POLAR, ED, M_ID, TLOC, MDUR, SIG);
			}
			else if (typeOFmission == 'E') {
				E = new FEvent(EMERGENCY, ED, M_ID, TLOC, MDUR, SIG);
			}
		}
		else if (Event_Type == 'X') {
			InputFile >> ED;
			InputFile >> M_ID;
			E = new CEvent(ED, M_ID);
		}
		else if (Event_Type == 'P') {
			InputFile >> ED;
			InputFile >> M_ID;
			E = new PEvent(ED, M_ID);
		}
		EventList.enqueue(E);
	}
}
bool MarsStation::DeleteFromMountList(int id, Missions* m)
{

	int i = 1;
	Missions* temp;
	while (!Mountainous_Missions.isEmpty()) 
	{	
		temp = Mountainous_Missions.getEntry(i);
		if (temp) 
		{
			if (temp->getID() == id) {
				m = temp;
				break;
			}
		}
		else {
			break;
		}

		i++;
	}

	if (m != nullptr) {
		Mountainous_Missions.remove(i);
		return true;
	}

	else
		return false;

}

void MarsStation::AddToEmergencyList(Missions* mis, float priority)
{
	Emergency_Missions.enqueue(mis, priority);
}

void MarsStation::AddToPolarList(Missions* pM)
{
	Polar_Missions.enqueue(pM);
}

void MarsStation::AddToMountList(Missions* mM)
{
	Mountainous_Missions.Add(mM);

}


void MarsStation::AssignToRover()
{
	while (!Emergency_Missions.isEmpty() && (!Emergency_Rovers.isEmpty() || !Mountainous_Rovers.isEmpty() || !Polar_Rovers.isEmpty()))
	{
		if (!Emergency_Rovers.isEmpty())
		{
			Missions* M;
			float pri = 0.0;
			float sig;
			Emergency_Missions.dequeue(M, pri);
			M->set_state(IN_EXCUTION);
			MissionsInExecutions.enqueue(M, pri);
			Rover* x = NULL;
			Emergency_Rovers.dequeue(x, sig);
			x->SetNumberOfOrderServed();
			RoversInExecution.enqueue(x, pri);
		}

		else if (!Mountainous_Rovers.isEmpty())
		{
			Missions* M = Mountainous_Missions.getEntry(1);
			Mountainous_Missions.remove(1);
			M->Assign();
			M->set_state(IN_EXCUTION);
			float pri = M->getFactorOfImportance();
			MissionsInExecutions.enqueue(M, pri);
			Rover* x = NULL;
			float f;
			Mountainous_Rovers.dequeue(x, f);
			x->SetNumberOfOrderServed();
			RoversInExecution.enqueue(x, pri);
		}
		else if (!Polar_Rovers.isEmpty())
		{
			Missions* M;
			Polar_Missions.dequeue(M);
			M->Assign();
			M->set_state(IN_EXCUTION);
			float pri = M->getFactorOfImportance();
			MissionsInExecutions.enqueue(M, pri);
			Rover* x = NULL;
			//Polar_Rovers.dequeue(x);
			x->SetNumberOfOrderServed();
			RoversInExecution.enqueue(x, pri);
		}
	}
	while (!Polar_Missions.isEmpty() && (!Polar_Rovers.isEmpty()))
	{

		if (!Polar_Rovers.isEmpty())
		{
			Missions* M;
			Polar_Missions.dequeue(M);
			M->Assign();
			M->set_state(IN_EXCUTION);
			float pri = M->getFactorOfImportance();
			MissionsInExecutions.enqueue(M, pri);
			Rover* x = NULL;
			float f;
			Polar_Rovers.dequeue(x, f);
			x->SetNumberOfOrderServed();
			RoversInExecution.enqueue(x, pri);
		}
	}
	while (!Mountainous_Missions.isEmpty() && (!Mountainous_Rovers.isEmpty() || !Emergency_Rovers.isEmpty()))
	{
		if (!Mountainous_Rovers.isEmpty())
		{
			Missions* M = Mountainous_Missions.getEntry(1);
			Mountainous_Missions.remove(1);
			M->Assign();
			M->set_state(IN_EXCUTION);
			float pri = M->getFactorOfImportance();
			MissionsInExecutions.enqueue(M, pri);
			Rover* x = NULL;
			float f;
			Mountainous_Rovers.dequeue(x, f);
			x->SetNumberOfOrderServed();
			RoversInExecution.enqueue(x, pri);
		}
		else if (!Emergency_Rovers.isEmpty())
		{
			Missions* M;
			float pri = 0.0;
			float sig;
			Emergency_Missions.dequeue(M, pri);
			M->set_state(IN_EXCUTION);
			MissionsInExecutions.enqueue(M, pri);
			Rover* x = NULL;
			Emergency_Rovers.dequeue(x, sig);
			x->SetNumberOfOrderServed();
			RoversInExecution.enqueue(x, pri);
		}
	}
	return;
}
void MarsStation::Simulation()
{
	//cout << "Enter Input File you want to read" << endl;
	//string s;
	////cin >> s;
	//ifstream Input;
	//Input.open("a.txt", ios::in);
	//GetInput(Input);


	//pointer to UI
	//UI->InteracTive

}