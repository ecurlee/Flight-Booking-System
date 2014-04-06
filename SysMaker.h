#ifndef SysMaker_h
#define SysMaker_h

#include "Common.h"
#include "HubNode.h"
#include "Date_Time.h"
#include "FlightNode.h"
#include "Iterator.h"
#include <sstream>

class SysMaker
{
private:
	HubNode *hnhead;
	void print_hl(HubNode *n);
	void del_hl(HubNode *n);

public:
	//hubs
	void del_hub_list();
	void print_hub_list();
	void build_hub_list();
	//flights
	void build_flight_list();

	HubNode *get_head(){return hnhead;}

	void debug_print();
	~SysMaker();
};

#endif