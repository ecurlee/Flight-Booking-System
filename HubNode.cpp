#include "HubNode.h"
#include "Iterator.h"

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

string HubNode::get_short_name()
{
	string abrev;
	if(0 == strcmp(name, "Tucson International Airport"))
	{
		abrev = "TUS";
	}
	else if(0 == strcmp(name, "Phoenix Sky Harbor International Airport"))
	{
		abrev = "PHX";
	}
	else if(0 == strcmp(name, "Los Angeles International Airport"))
	{
		abrev = "LAX";
	}
	else if(0 == strcmp(name, "Whiteman Airport"))
	{
		abrev = "WHP";
	}
	else if(0 == strcmp(name, "San Francisco International Airport"))
	{
		abrev = "SFO";
	}
	else if(0 == strcmp(name, "San Diego International Airport"))
	{
		abrev = "SAN";
	}
	else if(0 == strcmp(name, "Albany International Airport"))
	{
		abrev = "ALB";
	}
	else if(0 == strcmp(name, "Chicago Midway International Airport"))
	{
		abrev = "MDW";
	}
	else if(0 == strcmp(name, "Chicago O'Hare International Airport"))
	{
		abrev = "ORD";
	}
	else if(0 == strcmp(name, "General Edward Lawrence Logan International Airport"))
	{
		abrev = "BOS";
	}
	else if(0 == strcmp(name, "Mc Carran International Airport"))
	{
		abrev = "LAS";
	}
	else if(0 == strcmp(name, "John F Kennedy International Airport"))
	{
		abrev = "JFK";
	}
	else if(0 == strcmp(name, "Miami International Airport"))
	{
		abrev = "MIA";
	}
	else if(0 == strcmp(name, "Honolulu International Airport"))
	{
		abrev = "HNL";
	}
	else if(0 == strcmp(name, "Denver International Airport"))
	{
		abrev = "DIA";
	}
	else
	{
		abrev = location;
	}
	return abrev;
}

HubNode::~HubNode()
{
	Iterator iter;
	iter.clear_list(head);
}