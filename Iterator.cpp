#include "Iterator.h"


//-----------------------------------------------------------------------------------------------
FlightNode *Iterator::find(FlightNode *head, char flight_num[])
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
void Iterator::add(FlightNode **head, FlightNode *newNode)
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
	
void Iterator::clear_list(FlightNode *node)
{
	if(node)
	{
		clear_list(node->get_next());
		delete node;
	}
}
//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------
//add a flight to the end of the list
void Iterator::add(FlightNodeTracker **head, FlightNodeTracker *newNode)
{
	//creates a temporary node and sets it to head
	FlightNodeTracker *temp = *head;
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

//recursively removes the list
void Iterator::clear_list(FlightNodeTracker *node)
{
	if(node)
	{
		clear_list(node->get_next());
		delete node;
	}
}
//-----------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------
//finds a hub in the list
HubNode *Iterator::find_name(HubNode *head, string name)
{
	HubNode *current;
	current = head;
	//while there is a current node
	while(current)
	{
		//if it matches the requested hub name
		if(0 == name.compare(current->get_name()))
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

//add a hub to the end of the list
void Iterator::add(HubNode **head, HubNode *newNode)
{
	//creates a temporary node and sets it to head
	HubNode *temp = *head;
	//if there is no head
	if(!*head)
	{
		//sets the head to newNode;
		*head = newNode;
	}
	else
	{
		//while temp has a next node
		while(temp->get_next())
		{
			//advances to the next node
			temp = temp->get_next();
		}
		//adds the new node to the end of the list
		temp->set_next(newNode);
	}
}

HubNode *Iterator::find_loc(HubNode *head, string loc)
{
	HubNode *current;
	current = head;
	//while there is a current node
	while(current)
	{
		//if it matches the requested hub location
		if(0 == loc.compare(current->get_location()))
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
//-----------------------------------------------------------------------------------------------