#ifndef RouteList_h
#define RouteList_h

#include "FlightNode.h"
#include "Route.h"

class RouteList
{
public:
	Route *current;
	RouteList *next;

};

#endif