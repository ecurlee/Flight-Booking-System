#include "Common.h"
#include "FlightNode.cpp"
	
class FlightNodeIterator
{
public:
	//finds a flight in the list
	FlightNode *find(FlightNode *head, char flight_num[]);
	
	//add a flight to the end of the list
	void add(FlightNode **head, FlightNode *newNode);

	//finds the spcified flight and removes it from the list
	//returns true if the node was removed
	//false if it was not
	bool remove_flight(FlightNode **head, char flightnum[]);

	//recursively removes the list
	void clear_list(FlightNode *node);
};
