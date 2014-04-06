#include "Navigator.h"

Navigator::Navigator()
{
	start = NULL;
	dest = NULL;
	departure_time = NULL;
	head = NULL;
	max_hops = 4;
	min_hops = 0;
}

Navigator::Navigator(HubNode *startn, HubNode *destn, Date_Time *departure)
{
	start = startn;
	dest = destn;
	departure_time = departure;
	max_hops = 4;
	min_hops = 0;
}

void Navigator::reset()
{
	start = NULL;
	dest = NULL;
	departure_time = NULL;
	head = NULL;
	max_hops = 4;
	min_hops = 0;
}

//accessors
void Navigator::set_dest(HubNode *destn)	{dest = destn;}
void Navigator::set_start(HubNode *startn)	{start = startn;}
void Navigator::set_max(int max)			{max_hops = max;}
void Navigator::set_min(int min)			{min_hops = min;}
void Navigator::set_dep_time(Date_Time *dt)	{departure_time = dt;}

//mutators
HubNode *Navigator::get_dest()		{return dest;}
HubNode *Navigator::get_start()		{return start;}
int Navigator::get_max()			{return max_hops;}
int Navigator::get_min()			{return min_hops;}
Date_Time *Navigator::get_dep_time()	{return departure_time;}

//finds all possible routes within the desired number of hops
RouteList *Navigator::find_routes()
{
	FlightNode *temp;
	Date_Time *cur_time = departure_time;
	Date_Time *cur_time_temp;

	// sets the temp node to the outgoing flight
	temp = start->headFlight();
	//while there is a flightnode to work with
	while(temp)
	{
		//if the flight leaves after the time of arrival
		if(1 == comp_time(temp->get_departure(), cur_time))
		{
			//calculates the necessary delay
			cur_time_temp = cur_time->copy();
			cur_time_temp->add_min(temp->getDelay());
			//if the departure time is not before arival + delay
			if(-1 != comp_time(temp->get_departure(), cur_time_temp))
			{
				//copies the list
				FlightNodeTracker *newList = new FlightNodeTracker(temp);

				//if this flight will take you to the destination
				if(0 == strcmp(temp->get_destination()->get_location(), dest->get_location()))
				{
					//makes and adds a route
					add_route(new Route(newList, start, dest));
				}
				else
				{
					//continues searching
					flood(newList, max_hops - 1);
					//removes the list
					delete newList;
				}
			}
			delete cur_time_temp;
		}
		temp = temp->get_next();
	}
	return head;
}

//returns a copy of the flight list
FlightNodeTracker *Navigator::copy_list(FlightNodeTracker *source)
{
	FlightNodeTracker *copy = NULL;
	FlightNodeTracker *start = NULL;
	if(source)
	{
		copy = source->clone();
		start = copy;
		source = source->get_next();
		while(source)
		{
			copy->set_next(source->clone());
			copy = copy->get_next();
			source = source->get_next();
		}
	}
	return start;
}

//returns 1 if dt1 is > dt2, 0 if dt1 == dt2, and -1 if dt1 < dt2
int Navigator::comp_time(Date_Time *dt1, Date_Time *dt2)
{
	int total = 0;
	//checks each variable starting at year to see if one is greater than the other
	if(dt1->get_year() > dt2->get_year())
		return 1;
	else if(dt1->get_year() < dt2->get_year())
		return -1;
	if(dt1->get_month() > dt2->get_month())
		return 1;
	else if(dt1->get_month() < dt2->get_month())
		return -1;
	if(dt1->get_day() > dt2->get_day())
		return 1;
	else if(dt1->get_day() < dt2->get_day())
		return -1;
	if(dt1->get_hour() > dt2->get_hour())
		return 1;
	else if(dt1->get_hour() < dt2->get_hour())
		return -1;
	if(dt1->get_min() > dt2->get_min())
		return 1;
	else if(dt1->get_min() < dt2->get_min())
		return -1;
	return 0;
}

//initializes the head hub node
void Navigator::set_head(HubNode *h)
{
	hnhead = h;
}

void Navigator::flood(FlightNodeTracker *path, int num_hops)
{
	//if there are still hops available
	if(num_hops > 0)
	{
		FlightNodeTracker *temp = path;
		FlightNode *p;
		HubNode *cur_loc;
		Date_Time *cur_time;
		Date_Time *cur_time_temp;

		//advances to the end of the list
		while(temp->get_next())
		{
			temp = temp->get_next();
		}
		//gets the current location
		cur_loc = temp->get_flight()->get_destination();
		//figures out the landing time
		cur_time = temp->get_flight()->get_departure()->copy();
		cur_time->add_min(temp->get_flight()->get_duration());

		// sets the temp node to the outgoing flight
		p = cur_loc->headFlight();
		//while there is a flightnode to work with
		while(p)
		{
			//if the flight leaves after the time of arrival
			if(1 == comp_time(p->get_departure(), cur_time))
			{
				//calculates the necessary delay
				cur_time_temp = cur_time->copy();
				cur_time_temp->add_min(p->getDelay());
				//if the departure time is not before arival + delay
				if(-1 != comp_time(p->get_departure(), cur_time_temp))
				{
					Iterator iter;
					//copies the list
					FlightNodeTracker *newList = copy_list(path);
					//adds a copy of the current flight to the end of the list
					iter.add(&newList, new FlightNodeTracker(p));

					//if this flight will take you to the destination
					if(0 == strcmp(p->get_destination()->get_location(), dest->get_location()))
					{
						//makes a route
						Route *newRoute = new Route(newList, start, dest);
						//adds the route
						add_route(newRoute);
					}
					else
					{
						//continues searching
						flood(newList, num_hops - 1);
						//removes the list
						iter.clear_list(newList);
					}
				}
				delete cur_time_temp;
			}
			p = p->get_next();
		}
		delete cur_time;
	}
}

void Navigator::add_route(Route *n)
{
	//makes a new node
	RouteList *new_node = new RouteList();
	new_node->set_current(n);
	new_node->set_next(NULL);
	//if no head
	if(!head)
	{
		//sets head = new node
		head = new_node;
	}
	else
	{
		//creates a temp node to iterate through the list
		RouteList *p = head;
		//while there is a next node
		while(p->get_next())
		{
			//advances
			p = p->get_next();
		}
		//sets the last node's next to the new node
		p->set_next(new_node);
	}
}

//deconstructor
Navigator::~Navigator()
{
	destroy_routes(head);
}

void Navigator::destroy_routes(RouteList *n)
{
	if(n)
	{
		delete n->get_current();
		destroy_routes(n->get_next());
		delete n;
	}
}
