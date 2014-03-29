#ifndef Sort_h
#define Sort_h

#include "Common.h"
#include "FlightNode.h"
#include "Date_Time.h"
#include "Route.h"
#include "RouteList.h"


class Sort{

private:
	RouteList *route;

public:
	void set_routes(RouteList *routes);
	RouteList *get_routes();
	void reset();
	void sort_by_time();
	void sort_by_price();

};
#endif