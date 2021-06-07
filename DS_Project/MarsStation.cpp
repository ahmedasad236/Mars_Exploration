#include "MarsStation.h"
#include <fstream>
MarsStation::MarsStation()
{
	Mmissions = 0;
	Exit = 0;
	CurrentStep = 1;
	countAutoPromotion = 0;
	WaitingM = 0;
	InExecution = 0;
	Rovers = 0;
	CheckupRovers = 0;
	CompletedM = 0;
	formulated = 0;
	cancelled = 0;
	UImode = 0;
}

void MarsStation::AddToPolarRover(Rover* P)
{
	Polar_Rovers.enqueue(P, P->GetSpeed());
	Rovers++;
}
void MarsStation::AddToMountRover(Rover* M)
{
	Mountainous_Rovers.enqueue(M, M->GetSpeed());
	Rovers++;
}
void MarsStation::AddToEmerRover(Rover* E)
{
	Emergency_Rovers.enqueue(E, E->GetSpeed());
	Rovers++;
}

void MarsStation::printDay()
{
	userInterface.PrintWaiting(CurrentStep, WaitingM, Emergency_Missions, Polar_Missions, Mountainous_Missions);
	userInterface.PrintInExecution(InExecution, RoversInExecution);
	userInterface.PrintAvailableRovers(Rovers, Emergency_Rovers, Mountainous_Rovers, Polar_Rovers);
	userInterface.PrintCheckUp(CheckupRovers, RoversInCheckUp);
	userInterface.PrintCompleted(CompletedM, CompletedMissions);
}

void MarsStation::AutoPromote()
{
	Missions* Temp;
	int counter = 1;

	while (!Mountainous_Missions.isEmpty() && counter <= Mountainous_Missions.getLength()) 
	{
		Temp = Mountainous_Missions.getEntry(counter);

		if (Temp)
		{
			if (CurrentStep - Temp->getFD() == AutoP)
			{
				incrementAutoP();
				Temp->set_type(EMERGENCY);
				Missions* dummy = NULL;
				DeleteFromMountList(Temp->getID(), dummy);
				AddToEmergencyList(dummy, dummy->getPriority());
				counter--;
			}
		}

		counter++;
	}
}

void MarsStation::incrementAutoP()
{
	countAutoPromotion++;
}

void MarsStation::incrementCancelled()
{
	cancelled++;
}

void MarsStation::GetInput()
{

	ifstream InputFile;
	do
	{
		string name = "Input_TestCases/input";
		userInterface.EnterFileName();
		name += userInterface.getOutInFileNum(); // Set the name of the input file related to the input file
		InputFile.open(name);
	}while(!InputFile.is_open());

	InputFile >> no_mountainousR >> no_polarR >> no_EmerR;

	//getting the total number 
	int no_ofRovers = no_EmerR + no_mountainousR + no_polarR;
	Rovers = no_ofRovers;
	
	// If there is not any Rover, Exit the Program
	

	int* Mspeed = new int[no_mountainousR];		//Speeds of Mountainous Rovers
	int* Pspeed = new int[no_polarR];			//Speeds of Polar Rovers
	int* Espeed = new int[no_EmerR];			//Speeds of Emergency Rovers

	// Set Speed of Each Rover of Each Type
	for (int i = 0; i < no_mountainousR; i++)
		InputFile >> Mspeed[i];

	for (int i = 0; i < no_polarR; i++)
		InputFile >> Pspeed[i];

	for (int i = 0; i < no_EmerR; i++)
		InputFile >> Espeed[i];


	InputFile >> Max_Mission_before_checkup;

	//Reading Checkup Duration
	InputFile >> M_CK >> P_CK >> E_CK;

	//AutoP
	InputFile >> AutoP;

	
	int id = 0; // set Rovers' IDs

	for (int i = 0; i < no_mountainousR; i++) {
		Rover* M_ROVER = new Rover(++id, Mspeed[i], MOUNTAINOUS, M_CK, Max_Mission_before_checkup);
		Mountainous_Rovers.enqueue(M_ROVER, M_ROVER->GetSpeed());
	}

	for (int i = 0; i < no_polarR; i++) {
		Rover* P_ROVER = new Rover(++id, Pspeed[i], POLAR, P_CK, Max_Mission_before_checkup);
		Polar_Rovers.enqueue(P_ROVER, P_ROVER->GetSpeed());
	}

	for (int i = 0; i < no_EmerR; i++) {
		Rover* E_ROVER = new Rover(++id, Espeed[i], EMERGENCY, E_CK, Max_Mission_before_checkup);
		Emergency_Rovers.enqueue(E_ROVER, E_ROVER->GetSpeed());
	}

	InputFile >> no_events;
	char Event_Type;
	char typeOFmission;
	int ED; // Execution Duration 
	int M_ID; // Mission ID
	int TLOC; // Target Location
	int MDUR;  // Mission Duration
	int SIG;   // Mission Significance

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

			// if any Rover is available. Note: Mountainous Mission can be promoted to Emergency
			if (typeOFmission == 'M' ) {

					E = new FEvent(MOUNTAINOUS, ED, M_ID, TLOC, MDUR, SIG);
					formulated++;
					EventList.enqueue(E);
				
			}

			// Create a polar Event if there are polar rovers
			else if (typeOFmission == 'P' ) {

					E = new FEvent(POLAR, ED, M_ID, TLOC, MDUR, SIG);
					formulated++;
					EventList.enqueue(E);
					
			}


			// Create an Emergency Mission if any rover is available 
			else if (typeOFmission == 'E') {
				E = new FEvent(EMERGENCY, ED, M_ID, TLOC, MDUR, SIG);
				formulated++;
				EventList.enqueue(E);
			}
		}

		else if (Event_Type == 'X') {
			InputFile >> ED;
			InputFile >> M_ID;
			E = new CEvent(ED, M_ID);
			EventList.enqueue(E);
		}

		else if (Event_Type == 'P') {
			InputFile >> ED;
			InputFile >> M_ID;
			E = new PEvent(ED, M_ID);
			EventList.enqueue(E);
		}

		
	}

	// Deallocate the arrays
	delete[] Mspeed;
	delete[] Pspeed;
	delete[] Espeed;
	Mspeed = nullptr;
	Pspeed = nullptr;
	Espeed = nullptr;

	// Terminate the program if there is not any rover
	if (!no_ofRovers)
		Exit = 1;
	
}

bool MarsStation::DeleteFromMountList(int id, Missions* &m)
{
	int i = 1;
	Missions* temp = NULL;
	while (!Mountainous_Missions.isEmpty()) 
	{	
		temp = Mountainous_Missions.getEntry(i);
		if (temp) 
		{
			if (temp->getID() == id) 
			{
				m = temp;
				break;
			}
		}

		else 
			break;
		

		i++;
	}

	if (m != nullptr) {
		Mountainous_Missions.remove(i);
		WaitingM--;
		return true;
	}

	else
		return false;

}

void MarsStation::AddToEmergencyList(Missions* mis, float priority)
{
	WaitingM++;
	Emergency_Missions.enqueue(mis, priority);
}

void MarsStation::AddToPolarList(Missions* pM)
{
	 
	if (no_polarR > 0)
	{
		WaitingM++;
		Polar_Missions.enqueue(pM);
	}

	else
		formulated--;

}

void MarsStation::AddToMountList(Missions* mM)
{
	WaitingM++;
	Mmissions++;
	Mountainous_Missions.Add(mM);
}



void MarsStation::AssignToRover()
{
	Missions* M;
	Rover* x;
	float sig;
	float pri;
	while (!Emergency_Missions.isEmpty() && (!Emergency_Rovers.isEmpty() || !Mountainous_Rovers.isEmpty() || !Polar_Rovers.isEmpty()))
	{
		if (!Emergency_Rovers.isEmpty())
		{
			Emergency_Missions.dequeue(M, pri);
			M->set_state(IN_EXCUTION);
			M->setAssignDay(CurrentStep);
			Rover* x = NULL;
			Emergency_Rovers.dequeue(x, sig);
			x->SetNumberOfOrderServed();
			M->setSpeed(x->GetSpeed());
			x->setMission(M);
			Rovers--;
			WaitingM--;
			InExecution++;
			RoversInExecution.enqueue(x, -M->getLastDay());
		}

		else if (!Mountainous_Rovers.isEmpty())
		{
			Emergency_Missions.dequeue(M, pri);
			M->Assign();
			M->set_state(IN_EXCUTION);
			M->setAssignDay(CurrentStep);
			float pri = M->getPriority();
			Rover* x = NULL;
			float f;
			Mountainous_Rovers.dequeue(x, f);
			x->SetNumberOfOrderServed();
			M->setSpeed(x->GetSpeed());
			x->setMission(M);
			Rovers--;
			WaitingM--;
			InExecution++;
			RoversInExecution.enqueue(x, -M->getLastDay());
			
		}
		else if (!Polar_Rovers.isEmpty())
		{
			Emergency_Missions.dequeue(M, pri);
			M->Assign();
			M->set_state(IN_EXCUTION);
			M->setAssignDay(CurrentStep);
			pri = M->getPriority();
			x = NULL;
			float f;
			Polar_Rovers.dequeue(x,f);
			x->SetNumberOfOrderServed();
			M->setSpeed(x->GetSpeed());
			x->setMission(M);
			Rovers--;
			WaitingM--;
			InExecution++;
			RoversInExecution.enqueue(x, -M->getLastDay());
		}
	}

	while (!Polar_Missions.isEmpty() && (!Polar_Rovers.isEmpty()))
	{
		if (!Polar_Rovers.isEmpty())
		{
			Polar_Missions.dequeue(M);
			M->Assign();
			M->set_state(IN_EXCUTION);
			M->setAssignDay(CurrentStep);
			pri = M->getPriority();
			x = NULL;
			float f;
			Polar_Rovers.dequeue(x, f);
			x->SetNumberOfOrderServed();
			M->setSpeed(x->GetSpeed());
			x->setMission(M);
			Rovers--;
			WaitingM--;
			InExecution++;
			RoversInExecution.enqueue(x, -M->getLastDay());
		}
	}
	while (!Mountainous_Missions.isEmpty() && (!Mountainous_Rovers.isEmpty() || !Emergency_Rovers.isEmpty()))
	{
		if (!Mountainous_Rovers.isEmpty())
		{
			M = Mountainous_Missions.getEntry(1);
			Mountainous_Missions.remove(1);
			M->Assign();
			M->set_state(IN_EXCUTION);
			M->setAssignDay(CurrentStep);
			x = NULL;
			float f;
			Mountainous_Rovers.dequeue(x, f);
			x->SetNumberOfOrderServed();
			M->setSpeed(x->GetSpeed());
			x->setMission(M);
			Rovers--;
			WaitingM--;
			InExecution++;
			RoversInExecution.enqueue(x, -M->getLastDay());
		}

		else if (!Emergency_Rovers.isEmpty())
		{
			M;
			pri = 0.0;
			sig;
			M = Mountainous_Missions.getEntry(1);
			Mountainous_Missions.remove(1);
			M->set_state(IN_EXCUTION);
			M->setAssignDay(CurrentStep);
			x = NULL;
			Emergency_Rovers.dequeue(x, sig);
			x->SetNumberOfOrderServed();
			M->setSpeed(x->GetSpeed());
			x->setMission(M);
			Rovers--;
			WaitingM--;
			InExecution++;
			RoversInExecution.enqueue(x, -M->getLastDay());
		}
	}
	return;
}

void MarsStation::ExecuteEvent()
{
	Event* event = NULL;
	bool test =  EventList.peekFront(event);
	
	while (test && CurrentStep == event->getEventDay())
	{

		FEvent* E = dynamic_cast<FEvent*>(event);

		if (E)
		{
			if (E->getMissionType() == POLAR && !no_polarR)
				--formulated, userInterface.PrintFailer(POLAR);

			else
				E->Execute(this);
		}

		else
		{
			PEvent* E = dynamic_cast<PEvent*>(event);
			
			if (E)
				E->Execute(this);
			
			else
			{
				CEvent* E = dynamic_cast<CEvent*>(event);
				E->Execute(this);
			}
		}

		EventList.dequeue(event);
		test = EventList.peekFront(event);
	}
}

void MarsStation::outputFile()
{
	ofstream outputFile;
	string outName = "Output_TestCases/Output";
	outName += userInterface.getOutInFileNum(); // Set the name of the output file related to the input file
	outputFile.open(outName);
	outputFile.clear();
	outputFile << "CD " << "ID " << "WD " << "ED" << endl;

	////body
	Missions* m;
	int count = 0;
	int countM = 0, countP = 0, countE = 0;
	double AvgWait = 0;
	double AvgExec = 0;
	while (CompletedMissions.dequeue(m))
	{
		count++;

		if (m->get_type() == MOUNTAINOUS)
			countM++;
		
		else if (m->get_type() == POLAR)
			countP++;
		
		else if (m->get_type() == EMERGENCY)
			countE++;
		
		AvgWait += m->getWD();
		AvgExec += m->getED();
		outputFile << m->getLastDay() << " " << m->getID() << " " << m->getFD() << " " << m->getWD() << " " << m->getED() << endl;
	}

	if (count)
	{
		AvgWait = AvgWait / count;
		AvgExec = AvgExec / count;
	}
	
	/////////// here we should access no of rovers
	outputFile << "Missions: " << count << " [M:" << countM << ", P:" << countP << ", E:" << countE << "]\n";
	outputFile << "Rovers: " << (no_EmerR + no_mountainousR + no_polarR) << "[M:" << no_mountainousR << ", P:" << no_polarR << ", E:" << no_EmerR << "]\n";
	outputFile << "Avg Wait = " << AvgWait << ", " << "AvgExec =" << AvgExec << endl;
	outputFile << "Auto-promoted: " << (Mmissions != 0 ? (double)countAutoPromotion / (Mmissions) * 100 : 0) << "%" << endl;
	outputFile.close();
}

MarsStation::~MarsStation()
{
	
}

void MarsStation::endCheckUp()
{
	Rover* myRover;
	float pri = 0;
	while (RoversInCheckUp.peekFront(myRover, pri))
	{
		if (myRover->getDurationDay_ending() == CurrentStep)
		{
			RoversInCheckUp.dequeue(myRover, pri);
			CheckupRovers--;
			Rovers++;
			pri = myRover->GetSpeed();

			if (myRover->GetType() == MOUNTAINOUS)
			{
				Mountainous_Rovers.enqueue(myRover, pri);
			}
			else if (myRover->GetType() == EMERGENCY)
			{
				Emergency_Rovers.enqueue(myRover, pri);
			}

			else 
			{
				Polar_Rovers.enqueue(myRover, pri);
			}
		}
		else
		{
			break;
		}
	}
}

bool MarsStation::startCheckUp(Rover* myRover)
{
	if (myRover->GetNumberOfOrderServed() == myRover->GetMaxMissionBeforeCheckup())
	{
		myRover->SetNumberOfOrderServed(0);
		myRover->setDurationDay_starting(CurrentStep);
		RoversInCheckUp.enqueue(myRover, -myRover->getDurationDay_ending());  // minus here because we wanting the smaller ending day (day come first)
		return true;														  // to be at the top of the queue (1 feb is earlier than 4 feb but smaller
	}

	else return false;
}

void MarsStation::checkCompleted()
{
	Missions* myMission = NULL;
	Rover* myRover = NULL;
	float pri = 0;
	M_TYPE mt;
	while (RoversInExecution.peekFront(myRover, pri))
	{
		if (myRover->getMission()->getLastDay() == CurrentStep)
		{
			RoversInExecution.dequeue(myRover, pri);
			myMission = myRover->getMission();
			CompletedMissions.enqueue(myMission);

			if (startCheckUp(myRover))
				CheckupRovers++;

			else
			{
				mt = myRover->GetType();
				switch (mt)
				{
				case MOUNTAINOUS:
					AddToMountRover(myRover);
					break;
				case POLAR:
					AddToPolarRover(myRover);
					break;
				case EMERGENCY:
					AddToEmerRover(myRover);
					break;
				default:
					break;
				}
			}

			InExecution--;
			CompletedM++;
		}

		else
			break;
		
	}
}

void MarsStation::dayDetails()
{
	ExecuteEvent();
	AutoPromote();
	endCheckUp();
	AssignToRover();
	checkCompleted();
	if(UImode != 2)
		printDay();
	CurrentStep++;
}


int MarsStation::getCountAutoPromotion()
{
	return countAutoPromotion;
}

void MarsStation::Simulation()
{
	GetInput();
	UImode = userInterface.ChooseMode();
	
	if (Exit)
	{
		userInterface.PrintFailer(MOUNTAINOUS);
		outputFile();
		return;
	}

	if (UImode == 1)
		while (userInterface.interActiveMode() && CompletedM != formulated - cancelled)
			dayDetails();

	else if (UImode == 3)
		while (userInterface.StepByStep() && CompletedM != formulated - cancelled)
			dayDetails();


	else
	{
		userInterface.SlientMode(0);
		while (CompletedM != formulated - cancelled)
			dayDetails();
	}

	outputFile();
	userInterface.SlientMode(1);
}