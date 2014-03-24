#include "HubNode.h"


HubNode::HubNode(char nameOfHub[], char locationOfHub[])
{
	strcpy(name, nameOfHub);
	strcpy(location, locationOfHub);
	next = NULL;
	head = NULL;
}

HubNode *HubNode::get_next()		{return next;}

char *HubNode::get_name()			{return name;}
char *HubNode::get_location()		{return location;}

FlightNode *HubNode::headFlight()	{return head;}

void HubNode::set_next(HubNode *n)	{next = n;}


void HubNode::add_flight(FlightNode *n)
{
	FlightNode *temp;
	if(!head)
	{
		head = n;
	}
	else
	{
		temp = head;
		while(temp->get_next())
		{
			temp = temp->get_next();
		}
		temp->set_next(n);
	}
}