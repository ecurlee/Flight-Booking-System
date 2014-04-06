#ifndef Iterator_h
#define Iterator_h

#include "Common.h"
#include "FlightNode.h"
#include "HubNode.h"


class Iterator
{
public:
	//----------------------------------------------------------------------------------
	//finds a flight in the list
	FlightNode *find(FlightNode *head, char flight_num[]);
	
	//add a flight to the end of the list
	void add(FlightNode **head, FlightNode *newNode);

	//recursively removes the list
	void clear_list(FlightNode *node);
	//----------------------------------------------------------------------------------

	
	//----------------------------------------------------------------------------------
	//add a flight tracker to the end of the list
	void add(FlightNodeTracker **head, FlightNodeTracker *newNode);

	//recursively removes the list
	void clear_list(FlightNodeTracker *node);
	//----------------------------------------------------------------------------------

	
	//----------------------------------------------------------------------------------
	//finds a hub in the list
	HubNode *find_name(HubNode *head, string name);
	HubNode *find_loc(HubNode *head, string name);

	//add a hub to the end of the list
	void add(HubNode **head, HubNode *newNode);
	//----------------------------------------------------------------------------------
};

#endif