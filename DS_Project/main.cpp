#include<iostream>
#include"MarsStation.h"
using namespace std;
int main()
{
	MarsStation* Start = new MarsStation();;
	Start->Simulation();
	cout << "DONE Ya 7ag A7MED \n";
	delete Start;
	return 0;
}