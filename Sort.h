#ifndef Sort_h
#define Sort_h

#include "Common.h"
#include "FlightNode.h"
#include "Date_Time.h"
#include "Route.h"


class Sort{

private:
	int bags;
	RouteList *route;
	Date_Time *get_time(FlightNodeTracker *fnt);
	long get_dur(FlightNodeTracker *head);
	double Sort::get_price(FlightNodeTracker *head, int num_bags);

public:
	Sort(RouteList *rt, int num_bags);
	void set_routes(RouteList *routes);
	RouteList *get_routes();
	void set_num_bags(int num_bags);
	void reset();
	void sort_by_time();
	bool sort_by_time(int num_hops);
	void sort_by_price();
	bool sort_by_price(int num_hops);

};

#endif