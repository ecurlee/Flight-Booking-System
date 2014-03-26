#include "Navigator.h"

Navigator::Navigator()
{
	start = NULL;
	dest = NULL;
	max_hops = 4;
	min_hops = 0;
}

Navigator::Navigator(HubNode *startn, HubNode *destn)
{
	start = startn;
	dest = destn;
	max_hops = 4;
	min_hops = 0;
}

void Navigator::reset()
{
	start = NULL;
	dest = NULL;
	max_hops = 4;
	min_hops = 0;
}

void Navigator::set_dest(HubNode *destn)
{
	dest = destn;
}

void Navigator::set_start(HubNode *startn)
{
	start = startn;
}

void Navigator::set_max(int max)
{
	max_hops = max;
}

void Navigator::set_min(int min)
{
	min_hops = min;
}

HubNode *Navigator::get_dest()
{
	return dest;
}

HubNode *Navigator::get_start()
{
	return start;
}

int Navigator::get_max()
{
	return max_hops;
}

int Navigator::get_min()
{
	return min_hops;
}

RouteList *find_routes()
{

}