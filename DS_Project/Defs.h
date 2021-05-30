#pragma once
#include "LinkedList.h"
#include "cmath"
#include "PriorityQueue.h"
#include "Queue.h"
#include <fstream>
#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <Windows.h>
enum M_TYPE {
	MOUNTAINOUS,
	POLAR,
	EMERGENCY
};
enum M_STATUS {
	WAITING, IN_EXCUTION, COMPLETED
};