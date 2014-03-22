#include "FlightListIterator.h"


//finds a FlightNode give the flight number
FlightNode* FlightListIterator::find(FlightNode *head, char flight_num[])
{
	FlightNode *current;
	current = head;
	//while there is a current node
	while(current)
	{
		//if it matches the requested flight number
		if(0 == strcmp(current->get_flight_num(), flight_num))
		{
			//returns the current location
			return current;
		}
		//goes to the next element
		current = current->get_next();
	}
	//if no match is found, returns null
	return NULL;
}

//add a flight to the end of the list
void FlightListIterator::add(FlightNode **head, FlightNode *newNode)
{
	//creates a temporary node and sets it to head
	FlightNode *temp = *head;
	//if there is no head
	if(!*head)
	{
		//sets the head to newNode;
		*head = newNode;
	}
	//while temp has a next node
	while(temp->get_next())
	{
		//advances to the next node
		temp = temp->get_next();
	}
	//adds the new node to the end of the list
	temp->set_next(newNode);
}

//finds the spcified flight and removes it from the list
//returns true if the node was removed
//false if it was not
bool FlightListIterator::remove_flight(FlightNode **head, char flightnum[])
{
	//creates a temporary node and sets it to the head
	FlightNode *temp = *head;
	//if no head
	if(!head)
	{
		//cannot remove
		return false;
	}
	//if the head is the node
	if(0 == strcmp(flightnum, (*head)->get_flight_num()))
	{
		//replaces head with the next node in the list and frees the old node
		temp = temp->get_next();
		delete *head;
		temp = *head;
		//returns success
		return true;
	}
	//while there is a next node
	while(temp->get_next())
	{
		//if the next node is the desired node
		if(0 == strcmp(temp->get_next()->get_flight_num(), flightnum))
		{
			//removes the node
			FlightNode *p = temp->get_next()->get_next();
			delete temp->get_next();
			temp->set_next(p);
			//returns success
			return true;
		}
		//advances to the next node
		temp = temp->get_next();
	}
	//if this section is reached, the filght node was unable to be reached
	return false;
}