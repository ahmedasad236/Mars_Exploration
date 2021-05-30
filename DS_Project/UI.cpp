#include "UI.h"

UI::UI()
{

}

int UI::ChooseMode()
{
	int x;
	int count = 0;

	cout <<Color(4 , "****** Welcome To Our Mars Station :) *******\n");
	
	do {
		if (count)
			cout << Color(1,"Please, Choose a valid choice :)\n\n");

		cout << Color(1, "Choose the Desired Mode\n");
		cout << Color(1, "(1)To Enter InterActive Mode \n");
		cout << Color(1, "(2)To Enter Silent Mode \n");
		cout << Color(1, "(3)To Enter StepByStep Mode \nchoice: ");
		cin >> x;
		cout << Color(1, "--------------------------------------------------\n");

	} while (x < 1 || x > 3);

	return x;
}

void UI::SlientMode(int i)
{
	if (i == 0)
	{
		cout << Color(6, "Silent Mode\nSimulation Starts...\n");
	}
	else
		cout << Color(6, "Simulation ends, Output file created");
}

bool UI::StepByStep()
{
	// Waiting for 1 Seconds
	this_thread::sleep_for(chrono::milliseconds(1000));
	return 1;
}

bool UI::interActiveMode()
{
	cout <<Color(6,  "Press Enter to Display Day by Day\n");
	cin.get();
	return 1;
}

void UI::PrintWaiting(int day, int waiting, PriorityQueue<Missions*> &E, Queue<Missions*> &P, LinkedList<Missions*> &M)
{
	cout << Color(3, "Day: ") << Color(3, day) << "\n";
	cout << Color(3, waiting) << Color(3, " Waiting Missions: ");
	PriorityQueue<Missions*>TempE;

	Missions* temp = NULL;
	float priority = 0.0;

	// Print Emergency
	cout << Color(2, "[");
	bool test = E.peekFront(temp, priority);
	while (test)
	{
		cout << Color(2, temp->getID()) << Color(2, " ");
		E.dequeue(temp, priority);
		TempE.enqueue(temp, priority);
		test = E.peekFront(temp, priority);
	}
	cout << Color(2, "]  ");

	// Print Polar
	cout << Color(4, "( ");
	Queue<Missions*>TempP;
	test = P.peekFront(temp);
	while (test)
	{
		cout << Color(4, temp->getID()) << Color(4, " ");
		P.dequeue(temp);
		TempP.enqueue(temp);
		test = P.peekFront(temp);
	}
	cout << Color(4, ")  ");

	// Print Mountainous
	cout << Color(6, "{ ");
	int pos = 1;
	Node<Missions*>* ptr = M.getNodeAt(pos);
	while (ptr)
	{
		cout << Color(6, ptr->getItem()->getID()) << Color(6, " ");
		pos++;
		ptr = M.getNodeAt(pos);
	}
	cout <<Color(6,  "}");

	// Put the data again in its original ADT
	while (TempP.dequeue(temp))
		P.enqueue(temp);

	while (TempE.dequeue(temp, priority))
		E.enqueue(temp, priority);
	cout << Color(3, "\n----------------------------------------------------------------------------------\n");

}

void UI::PrintInExecution(int inExecution, PriorityQueue<Rover*> &rovers)
{
	cout << Color(3, inExecution) <<Color(3,  "  In-Execution Missions/Rovers: ");
	PriorityQueue<Rover*>tempP;
	PriorityQueue<Rover*>tempM;
	PriorityQueue<Rover*>tempE;
	Rover* tempr = NULL;
	float prR = 0.0;

	while (rovers.dequeue(tempr, prR))
	{
		if (tempr->getMission()->get_type() == EMERGENCY)
			tempE.enqueue(tempr, prR);

		else if (tempr->getMission()->get_type() == POLAR)
			tempP.enqueue(tempr, prR);

		else
			tempM.enqueue(tempr, prR);
	}
	
	cout <<Color(2,  "[");
	while (tempE.dequeue(tempr, prR))
	{
		cout << Color(2, tempr->getMission()->getID()) << Color(2, "/") << Color(2, tempr->GetID()) << Color(2, "  ");
		rovers.enqueue(tempr, prR);
	}
	cout <<Color(2,  "]  ");

	cout << Color(4, "( ");
	while (tempP.dequeue(tempr, prR))
	{
		cout << Color(4, tempr->getMission()->getID()) << Color(4, "/") << Color(4, tempr->GetID()) << Color(4, "  ");
		rovers.enqueue(tempr, prR);
	}
	cout << Color(4, ")  ");

	cout << Color(6, "{ ");
	while (tempM.dequeue(tempr, prR))
	{
		cout << tempr->getMission()->getID() << "/" << tempr->GetID() << "  ";
		rovers.enqueue(tempr, prR);
	}
	cout << Color(6, "}  ");

	cout << Color(3, "\n----------------------------------------------------------------------------------\n");
}

void UI::PrintAvailableRovers(int available, PriorityQueue<Rover*> &E, PriorityQueue<Rover*> &M, PriorityQueue<Rover*> &P)
{
	cout << Color(3, available) << Color(3, " Available Rovers: ");
	PriorityQueue<Rover*>TempE;
	PriorityQueue<Rover*>TempP;
	PriorityQueue<Rover*>TempM;
	Rover* temp = NULL;
	float priority = 0.0;

	while (E.dequeue(temp, priority))
		TempE.enqueue(temp, priority);

	while (M.dequeue(temp, priority))
		TempM.enqueue(temp, priority);

	while (P.dequeue(temp, priority))
		TempP.enqueue(temp, priority);

	// Print Emergency
	cout <<Color(2,  "[");
	while (TempE.dequeue(temp, priority))
	{
		cout << Color(2, temp->GetID()) << Color(2, " ");
		E.enqueue(temp, priority);
	}
	cout << Color(2, "]  ");

	// Print Polar
	cout <<Color(4,  "( ");
	while (TempP.dequeue(temp, priority))
	{

		cout << Color(4, temp->GetID()) <<Color(4,  " ");
		P.enqueue(temp, priority);
		
	}
	cout << Color(4, ")  ");

	// Print Mountainous
	cout << Color(6, "{ ");
	while (TempM.dequeue(temp, priority))
	{

		cout << Color(6, temp->GetID()) << Color(6, " ");
		M.enqueue(temp, priority);
		
	}
	cout << Color(6, "}  ");

	cout << Color(3, "\n----------------------------------------------------------------------------------\n");

}

void UI::PrintCheckUp(int incheckup, PriorityQueue<Rover*> &check)
{
	cout << Color(3, incheckup) << Color(3, "  In-Checkup Rovers: ");
	PriorityQueue<Rover*>TempP;
	PriorityQueue<Rover*>TempE;
	PriorityQueue<Rover*>TempM;

	Rover* tempr = NULL;
	float prR = 0.0;
	while (check.dequeue(tempr, prR))
	{
		if (tempr->GetType() == EMERGENCY)
			TempE.enqueue(tempr, prR);

		else if (tempr->GetType() == POLAR)
			TempP.enqueue(tempr, prR);

		else
			TempM.enqueue(tempr, prR);
	}

	cout << Color(2, "[");
	while (TempE.dequeue(tempr, prR))
	{
		cout << Color(2, tempr->GetID()) << Color(2, "  ");
		check.enqueue(tempr, prR);
	}
	cout << Color(2, "]  ");

	cout << Color(4, "( ");
	while (TempP.dequeue(tempr, prR))
	{
		cout << Color(4, tempr->GetID()) << Color(4, "  ");
		check.enqueue(tempr, prR);
	}
	cout << Color(4, ")  ");

	cout << Color(6, "{ ");
	while (TempM.dequeue(tempr, prR))
	{
		cout << Color(6, tempr->GetID()) << Color(6, "  ");
		check.enqueue(tempr, prR);
	}
	cout << Color(6, "}  ");

	
	cout <<Color(3, "\n----------------------------------------------------------------------------------\n");

}

void UI::PrintCompleted(int comp, Queue<Missions*> &completed)
{
	cout << Color(3, comp) << Color(3, "  Completed Missions: ");
	Queue<Missions*>TempE;
	Queue<Missions*>TempM;
	Queue<Missions*>TempP;

	Missions* temp = NULL;

	while (completed.dequeue(temp))
	{
		if (temp->get_type() == EMERGENCY)
			TempE.enqueue(temp);

		else if (temp->get_type() == POLAR)
			TempP.enqueue(temp);

		else
			TempM.enqueue(temp);
	}
	
	cout << Color(2, "[");
	while (TempE.dequeue(temp))
	{
		cout << Color(2, temp->getID()) << Color(2, " ");
		completed.enqueue(temp);
	}
	cout << Color(2, "]");

	cout << Color(4, "(");
	while (TempP.dequeue(temp))
	{
		cout << Color(4, temp->getID()) << Color(4, " ");
		completed.enqueue(temp);
	}
	cout << Color(4, ")");

	cout << Color(6, "{");
	while (TempM.dequeue(temp))
	{
		cout << Color(6, temp->getID()) << Color(6, " ");
		completed.enqueue(temp);
	}
	cout << Color(6, "}");

	cout << Color(3, "\n----------------------------------------------------------------------------------\n");

}