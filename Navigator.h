#ifndef Navigator_h
#define Navigator_h

#include "Common.h"
#include "HubNode.h"
#include "FlightNode.h"
#include "Route.h"
#include "RouteList.h"

class Navigator
{
private:
	HubNode *start;
	HubNode *dest;
	int max_hops;
	int min_hops;
	
public:
	Navigator();
	Navigator(HubNode *startn, HubNode *destn);
	void reset();
	void set_dest(HubNode *destn);
	void set_start(HubNode *startn);
	void set_max(int max);
	void set_min(int min);
	HubNode *get_start();
	HubNode *get_dest();
	int get_max();
	int get_min();
	RouteList *find_routes();
};

#endif