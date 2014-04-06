#ifndef Navigator_h
#define Navigator_h

#include "Common.h"
#include "HubNode.h"
#include "FlightNode.h"
#include "Route.h"

class Navigator
{
private:
	HubNode *start;
	HubNode *dest;
	HubNode *hnhead;
	RouteList *head;
	Date_Time *departure_time;
	int max_hops;
	int min_hops;
	FlightNodeTracker *copy_list(FlightNodeTracker *source);
	int comp_time(Date_Time *dt1, Date_Time *dt2);
	void add_route(Route *newNode);
	void flood(FlightNodeTracker *path, int num_hops);
	void destroy_routes(RouteList *n);
	
public:
	Navigator();
	Navigator(HubNode *startn, HubNode *destn, Date_Time *departure);
	void reset();
	void set_dest(HubNode *destn);
	void set_start(HubNode *startn);
	void set_head(HubNode *h);//should only be called once
	void set_max(int max);
	void set_min(int min);
	void set_dep_time(Date_Time *dt);
	Date_Time *get_dep_time();
	HubNode *get_start();
	HubNode *get_dest();
	int get_max();
	int get_min();
	RouteList *find_routes();
	~Navigator();
};

#endif