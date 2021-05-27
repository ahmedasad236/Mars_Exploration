#include<iostream>
#include"MarsStation.h"
using namespace std;
int main()
{
	MarsStation* Start = new MarsStation();
	Start->Simulation();

	delete Start;
	return 0;
}