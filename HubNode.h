#ifndef HubNode_h
#define HubNode_h

#include "Common.h"
#include "FlightNode.h"

class HubNode
{
private:
	char name[56];
	char location[16];
	HubNode *next;
	FlightNode *head;

public:
	HubNode(char nameOfHub[], char locationOfHub[]);
	HubNode *get_next();
	char *get_name();
	char *get_location();

	void set_next(HubNode *n);

	FlightNode *headFlight();
	void add_flight(FlightNode *n);
};

#endif