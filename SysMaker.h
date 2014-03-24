#ifndef SysMaker_h
#define SysMaker_h

#include "Common.h"
#include "HubNode.h"
#include "HubNodeIterator.h"
#include "Date_Time.h"
#include "FlightNode.h"
#include "FlightNodeTracker.h"
#include <sstream>

class SysMaker
{
private:
	HubNode *hnhead;
	FlightNodeTracker *fnthead;
	void print_hl(HubNode *n);
	void del_hl(HubNode *n);
	void del_fl(FlightNodeTracker *n);
	void print_fl(FlightNodeTracker *n);

public:
	//hubs
	void del_hub_list();
	void print_hub_list();
	void build_hub_list();
	//nodes
	void del_flight_list();
	void print_flight_list();
	void build_flight_list();

	void debug_print();
	~SysMaker();
};

#endif