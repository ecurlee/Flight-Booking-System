#ifndef Route_h
#define Route_h

#include "Common.h"
#include "FlightNode.h"
#include "HubNode.h"
#include "Date_Time.h"
#include <string>
#include "Iterator.h"

//-------------------------------------------------------------------------
class Route
{
private:
	FlightNodeTracker *flight_list;
	HubNode *start;
	HubNode *destination;
	int num_flights;
	long get_time();
	double get_price(int num_bags);


public:
	FlightNodeTracker *get_flights();
	HubNode *get_dest();
	HubNode *get_start();
	int get_num_flights();

	Route(FlightNodeTracker *flight_list, HubNode *start, HubNode *dest);
		
	void print_route(int num_bags);

	~Route();
};
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
class RouteList
{
private:
	Route *current;
	RouteList *next;

public:
	Route *get_current();
	RouteList *get_next();
	void set_current(Route *n);
	void set_next(RouteList *n);

};
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
class RouteListManipulator
{
private:
	//note: this is the node before the desired node
	void remove_next(RouteList *p);

public:
	void set_to_head(RouteList *head, RouteList *p);
	void clear_data(RouteList *head);
};
//-------------------------------------------------------------------------

#endif