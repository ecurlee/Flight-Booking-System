#include "Sort.h"

Sort::Sort(RouteList *rt, int num_bags)
{
	route = rt;
	bags = num_bags;
}

void Sort::set_routes(RouteList *routes)
{
	route = routes;
}

void Sort::set_num_bags(int num_bags)
{
	bags = num_bags;
}

RouteList *Sort::get_routes()
{
	return route;
}

void Sort::reset()
{
	route = NULL;
	bags = 0;
}

//sorts by time
void Sort::sort_by_time()
{
	if(route->get_next())
	{
		RouteList *old_head, *new_head, *cur_node, *max_node;
		long cur_max, temp_dur;
		//initializes both heads to new head
		old_head = route;
		new_head = route;
		//while the old head is not null
		while(old_head)
		{
			RouteListManipulator rlm;
			//initializes the current node and max node to the old head
			cur_node = old_head;
			max_node = old_head;
			//sets max to the current node's duration of travel
			cur_max = get_dur(cur_node->get_current()->get_flights());
			//until it reaches the end of the list
			while(cur_node)
			{
				//gets the current nodes duration
				temp_dur = get_dur(cur_node->get_current()->get_flights());
				//if the curent node's duration is greater than the max duration
				if(temp_dur > cur_max)
				{
					//sets max to current
					cur_max = temp_dur;
					//sets max node to current node
					max_node = cur_node;
				}
				//advances the node tracker
				cur_node = cur_node->get_next();
			}
			//if the max node is the old head
			if(max_node == old_head)
			{
				//advnaces the old head
				old_head = old_head->get_next();
			}
			//moves the max node to the head
			rlm.set_to_head(new_head, max_node);
			//sets the new head to max node
			new_head = max_node;
		}
		//changes route head to new head
		route = new_head;
	}
}

bool Sort::sort_by_time(int num_hops)
{
	bool any_change = false;
	if(num_hops == route->get_current()->get_num_flights())
	{
		any_change = true;
	}
	if(route->get_next())
	{
		RouteList *old_head, *new_head, *cur_node, *max_node;
		long cur_max, temp_dur;
		//initializes both heads to new head
		old_head = route;
		new_head = route;
		//while the old head is not null
		while(old_head)
		{
			RouteListManipulator rlm;
			//initializes the current node and max node to the old head
			cur_node = old_head;
			max_node = old_head;
			//sets max to the current node's duration of travel
			cur_max = get_dur(cur_node->get_current()->get_flights());
			//until it reaches the end of the list
			while(cur_node)
			{
				//gets the current nodes duration
				temp_dur = get_dur(cur_node->get_current()->get_flights());
				//if the curent node's duration is greater than the max duration
				if(temp_dur >= cur_max && num_hops == cur_node->get_current()->get_num_flights())
				{
					//sets max to current
					cur_max = temp_dur;
					//sets max node to current node
					max_node = cur_node;
					any_change = true;
				}
				//advances the node tracker
				cur_node = cur_node->get_next();
			}
			if(!any_change)
			{
				return any_change;
			}
			//if the max node is the old head
			if(max_node == old_head)
			{
				//advnaces the old head
				old_head = old_head->get_next();
			}
			//moves the max node to the head
			rlm.set_to_head(new_head, max_node);
			//sets the new head to max node
			new_head = max_node;
		}
		//changes route head to new head
		route = new_head;
	}
	return any_change;
}

//sorts by price
void Sort::sort_by_price()
{
	if(route->get_next())
	{
		//same as above, only with price
		RouteList *old_head, *new_head, *cur_node, *max_node;
		double cur_max, temp_price;
		old_head = route;
		new_head = route;
		while(old_head)
		{
			RouteListManipulator rlm;
			cur_node = old_head;
			max_node = old_head;
			cur_max = get_price(cur_node->get_current()->get_flights(), bags);
			while(cur_node)
			{
				temp_price = get_price(cur_node->get_current()->get_flights(), bags);
				if(temp_price > cur_max)
				{
					cur_max = temp_price;
					max_node = cur_node;
				}
				cur_node = cur_node->get_next();
			}
			if(max_node == old_head)
			{
				old_head = old_head->get_next();
			}
			rlm.set_to_head(new_head, max_node);
			new_head = max_node;
		}
		route = new_head;
	}
}

//sorts by price
bool Sort::sort_by_price(int num_hops)
{
	bool any_change = false;
	if(num_hops == route->get_current()->get_num_flights())
	{
		any_change = true;
	}
	if(route->get_next())
	{
		//same as above, only with price
		RouteList *old_head, *new_head, *cur_node, *max_node;
		double cur_max, temp_price;
		old_head = route;
		new_head = route;
		while(old_head)
		{
			RouteListManipulator rlm;
			cur_node = old_head;
			max_node = old_head;
			cur_max = get_price(cur_node->get_current()->get_flights(), bags);
			while(cur_node)
			{
				temp_price = get_price(cur_node->get_current()->get_flights(), bags);
				if(temp_price >= cur_max && num_hops == cur_node->get_current()->get_num_flights())
				{
					cur_max = temp_price;
					max_node = cur_node;
					any_change = true;
				}
				cur_node = cur_node->get_next();
			}
			if(!any_change)
			{
				return any_change;
			}
			if(max_node == old_head)
			{
				old_head = old_head->get_next();
			}
			rlm.set_to_head(new_head, max_node);
			new_head = max_node;
		}
		route = new_head;
	}
	return any_change;
}


//Im lazy
Date_Time *Sort::get_time(FlightNodeTracker *fnt)
{
	return fnt->get_flight()->get_departure();
}

//calculates the duration of a trip given the head flight (which is linked to subsequent flights
long Sort::get_dur(FlightNodeTracker *head)
{
	Date_Time *start_time = get_time(head);
	Date_Time *end;
	long end_time;
	FlightNodeTracker *temp = head;
	//advances to the end
	while(temp->get_next())
	{
		temp = temp->get_next();
	}
	//copies the time
	end = get_time(temp)->copy();
	//moves the time forward
	end->add_min(temp->get_flight()->get_duration());
	// CC: this is a function
	end_time = end->get_min_since_2013();
	delete end;
	//returns the difference
	return end_time - start_time->get_min_since_2013();
}

double Sort::get_price(FlightNodeTracker *head, int num_bags)
{
	FlightNodeTracker *p = head;
	double total = 0;
	//while there is an element
	while(p)
	{
		//adds the baggage fee to the total
		total += p->get_flight()->getBaggageFees(num_bags);
		//adds the flight cost to the total
		total += p->get_flight()->get_price();
		//advances
		p = p->get_next();
	}
	return total;
}
