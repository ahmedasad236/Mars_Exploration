#include "UI.h"

UI::UI()
{

}

int UI::ChooseMode()
{
	int x;
	int count = 0;
	cout << "****** Welcome To Our Mars Station :) *******\n";
	do {
		if (count)
			cout << "Please, Choose a valid choice :)\n\n";

		cout << "Choose the Desired Mode" << endl;
		cout << "(1)To Enter InterActive Mode " << endl;
		cout << "(2)To Enter Silent Mode " << endl;
		cout << "(3)To Enter StepByStep Mode " << endl << "choice: ";
		cin >> x;
		cout << "--------------------------------------------------\n";

	} while (x < 1 || x > 3);

	return x;
}

void UI::SlientMode(int i)
{
	if (i == 0)
	{
		cout << "Silent Mode" << endl << "Simulation Starts..." << endl;
	}
	else
		cout << "Simulation ends, Output file created";
}

bool UI::StepByStep()
{
	// Waiting for 2 Seconds
	this_thread::sleep_for(chrono::milliseconds(2000));
	return 1;
}

bool UI::interActiveMode()
{
	cout << "Press Enter to Display Day by Day\n";
	cin.get();
	return 1;
}

void UI::PrintWaiting(int day, int waiting, PriorityQueue<Missions*> &E, Queue<Missions*> &P, LinkedList<Missions*> &M)
{
	cout << "Day: " << day << "\n";
	cout << waiting << " Waiting Missions: ";
	PriorityQueue<Missions*>TempE;

	Missions* temp = NULL;
	float priority = 0.0;

	// Print Emergency
	cout << "[";
	bool test = E.peekFront(temp, priority);
	while (test)
	{
		cout << temp->getID() << " ";
		E.dequeue(temp, priority);
		TempE.enqueue(temp, priority);
		test = E.peekFront(temp, priority);
	}
	cout << "]  ";

	// Print Polar
	cout << "( ";
	Queue<Missions*>TempP;
	test = P.peekFront(temp);
	while (test)
	{
		cout << temp->getID() << " ";
		P.dequeue(temp);
		TempP.enqueue(temp);
		test = P.peekFront(temp);
	}
	cout << ")  ";

	// Print Mountainous
	cout << "{ ";
	int pos = 1;
	Node<Missions*>* ptr = M.getNodeAt(pos);
	while (ptr)
	{
		cout << ptr->getItem()->getID() << " ";
		pos++;
		ptr = M.getNodeAt(pos);
	}
	cout << "}";

	// Put the data again in its original ADT
	while (TempP.dequeue(temp))
		P.enqueue(temp);

	while (TempE.dequeue(temp, priority))
		E.enqueue(temp, priority);
	cout << "\n----------------------------------------------------------------------------------\n";

}

void UI::PrintInExecution(int inExecution, PriorityQueue<Rover*> &rovers)
{
	cout << inExecution << "  In-Execution Missions/Rovers: ";
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
	cout << "[";
	
	while (tempE.dequeue(tempr, prR))
	{
		cout << tempr->getMission()->getID() << "/" << tempr->GetID() << "  ";
		rovers.enqueue(tempr, prR);
	}
	cout << "]  ";

	cout << "( ";
	while (tempP.dequeue(tempr, prR))
	{
		cout << tempr->getMission()->getID() << "/" << tempr->GetID() << "  ";
		rovers.enqueue(tempr, prR);
	}
	cout << ")  ";

	cout << "{ ";
	while (tempM.dequeue(tempr, prR))
	{
		cout << tempr->getMission()->getID() << "/" << tempr->GetID() << "  ";
		rovers.enqueue(tempr, prR);
	}
	cout << "}  ";

	cout << "\n----------------------------------------------------------------------------------\n";
}

void UI::PrintAvailableRovers(int available, PriorityQueue<Rover*> &E, PriorityQueue<Rover*> &M, PriorityQueue<Rover*> &P)
{
	cout << available << " Available Rovers: ";
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
	cout << "[";
	while (TempE.dequeue(temp, priority))
	{
		cout << temp->GetID() << " ";
		E.enqueue(temp, priority);
	}
	cout << "]  ";

	// Print Polar
	cout << "( ";
	while (TempP.dequeue(temp, priority))
	{

		cout << temp->GetID() << " ";
		P.enqueue(temp, priority);
		
	}
	cout << ")  ";

	// Print Mountainous
	cout << "{ ";
	while (TempM.dequeue(temp, priority))
	{

		cout << temp->GetID() << " ";
		M.enqueue(temp, priority);
		
	}
	cout << "}  ";

	cout << "\n----------------------------------------------------------------------------------\n";

}

void UI::PrintCheckUp(int incheckup, PriorityQueue<Rover*> &check)
{
	cout << incheckup << "  In-Checkup Rovers: ";
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

	cout << "[";
	while (TempE.dequeue(tempr, prR))
	{
		cout << tempr->GetID() << "  ";
		check.enqueue(tempr, prR);
	}
	cout << "]  ";

	cout << "( ";
	while (TempP.dequeue(tempr, prR))
	{
		cout << tempr->GetID() << "  ";
		check.enqueue(tempr, prR);
	}
	cout << ")  ";

	cout << "{ ";
	while (TempM.dequeue(tempr, prR))
	{
		cout << tempr->GetID() << "  ";
		check.enqueue(tempr, prR);
	}
	cout << "}  ";

	
	cout << "\n----------------------------------------------------------------------------------\n";

}

void UI::PrintCompleted(int comp, Queue<Missions*> &completed)
{
	cout << comp << "  Completed Missions: ";
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
	
	cout << "[";
	while (TempE.dequeue(temp))
	{
		cout << temp->getID() << " ";
		completed.enqueue(temp);
	}
	cout << "]";

	cout << "(";
	while (TempP.dequeue(temp))
	{
		cout << temp->getID() << " ";
		completed.enqueue(temp);
	}
	cout << ")";

	cout << "{";
	while (TempM.dequeue(temp))
	{
		cout << temp->getID() << " ";
		completed.enqueue(temp);
	}
	cout << "}";

	cout << "\n----------------------------------------------------------------------------------\n";

}