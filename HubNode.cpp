#include "HubNode.h"


HubNode::HubNode(char nameOfHub[], char locationOfHub[])
{
	strcpy(name, nameOfHub);
	strcpy(location, locationOfHub);
}

HubNode *HubNode::get_next() {return next;}

FlightNode *HubNode::headFlight() {return head;}