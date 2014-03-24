#ifndef FlightNodeTracker_h
#define FlightNodeTracker_h

#include "Common.h"
#include "FlightNode.h"

class FlightNodeTracker
{
public:
	FlightNode *current;
	FlightNodeTracker *next;
};

#endif