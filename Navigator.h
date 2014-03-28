#ifndef Navigator_h
#define Navigator_h

#include "Common.h"
#include "HubNode.h"
#include "FlightNode.h"
#include "Route.h"
#include "RouteList.h"
#include "HubNodeIterator.h"
#include "FlightNodeIterator.h"

class Navigator
{
private:
	HubNode *start;
	HubNode *dest;
	HubNode *hnhead;
	RouteList *head;
	int max_hops;
	int min_hops;
	FlightNode *copy_list(FlightNode *source);
	int comp_time(Date_Time *dt1, Date_Time *dt2);
	void add_route(Route *newNode);
	void flood(FlightNode *path, int num_hops);
	
public:
	Navigator();
	Navigator(HubNode *startn, HubNode *destn);
	void reset();
	void set_dest(HubNode *destn);
	void set_start(HubNode *startn);
	void set_head(HubNode *h);//should only be called once
	void set_max(int max);
	void set_min(int min);
	HubNode *get_start();
	HubNode *get_dest();
	int get_max();
	int get_min();
	RouteList *find_routes();
};

#endif