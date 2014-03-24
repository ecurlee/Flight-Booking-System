#ifndef HubNodeIterator_h
#define HubNodeIterator_h

#include "Common.h"
#include "HubNode.h"

//class is used to perform functions on a FlightNode linked list
class HubNodeIterator
{
public:
	//finds a hub in the list
	HubNode *find(HubNode *head, char name[]);

	//add a hub to the end of the list
	void add(HubNode **head, HubNode *newNode);

	//finds the spcified hub and removes it from the list
	//returns true if the node was removed
	//false if it was not
	bool remove_node(HubNode **head, char name[]);
};

#endif