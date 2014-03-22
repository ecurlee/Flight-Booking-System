#ifndef HubNode_h
#define HubNode_h

#include "Common.h"
#include "FlightNode.h"
#include "FlightListIterator.h"
#include "Date_Time.h"
class HubNode
{
	private:
		char *name;
		char *location;//Changed to char* data type
		HubNode *next;
		FlightNode *head;//added

	public:
		HubNode(char nameOfHub[], char locationOfHub[]);
		HubNode *get_next();

		FlightNode *headFlight();
};

#endif