#include "Route.h"

//=====================================================================================================
Route::Route(FlightNodeTracker *flightlist, HubNode *strt, HubNode *dest)
{
		//create list with starting flight as the head
	flight_list = flightlist;
	start = strt;
	destination = dest;
	num_flights = 0;
	FlightNodeTracker *p = flightlist;
	while(p)
	{ 
		num_flights++;
		p = p->get_next();
	}
}

double Route::get_price(int num_bags)
{
	FlightNodeTracker *current = flight_list;
	double price = 0;
	//goes through each flight
	while(current)
	{
		//adds up the combined price of the flight and the baggage fees
		price += current->get_flight()->get_price();
		price += current->get_flight()->getBaggageFees(num_bags);
		current = current->get_next();
	}
	return price;
}

long Route::get_time()
{
	FlightNodeTracker *current = flight_list;
	Date_Time *start_time, *end_time;
	//if there are flights to work with
	if(current)
	{
		long st, et;
		//grabs the first flight's time
		start_time = current->get_flight()->get_departure()->copy();
		//loops to the end of the ll
		while(current->get_next())
		{
			current = current->get_next();
		}
		//grabs the last flight's time
		end_time = current->get_flight()->get_departure()->copy();
		//advances it by the duration of the flight
		end_time->add_min(current->get_flight()->get_duration());

		//gets the time for the end and start
		et = end_time->get_min_since_2013();
		st = start_time->get_min_since_2013();
		//delete the time copies
		delete end_time;
		delete start_time;

		//returns the difference
		return abs(et - st);
	}
	//returns error if no flights
	//should never be reached
	return -1;
}

//accessors
FlightNodeTracker *Route::get_flights()	
{
	return flight_list;
}

HubNode	*Route::get_dest()		{return destination;}

HubNode	*Route::get_start()		{return start;}

int Route::get_num_flights()	{return num_flights;} //# of flights in the route (# of hops)

void Route::print_route(int num_bags)
{
	FlightNodeTracker *fl = flight_list;
	cout << "Flight Number\tCompany\t\tSource Location\tDeparture Date/Time" << endl;
	while(fl)
	{
		Date_Time *temp;
		//prints the flight number
		cout << fl->get_flight()->get_flight_num() << "\t\t";
		//prints flight company
		cout << fl->get_flight()->get_flight_comp() << "\t";
		if(strlen(fl->get_flight()->get_flight_comp()) < 8)
		{
			cout <<"\t";
		}
		//prints the source hub's name
		cout << fl->get_flight()->get_source()->get_short_name() << "\t\t";
		//prints the departure time
		cout << fl->get_flight()->get_departure()->get_time() << endl;
		//prints the destination hub's name
		cout << "\t\t\t\t" << fl->get_flight()->get_destination()->get_short_name() << "\t\t";
		//prints the arrival time (without adjusting for time-zones)
		temp = fl->get_flight()->get_departure()->copy();
		temp->add_min(fl->get_flight()->get_duration());

		cout << temp->get_time() << endl;
		//print pricing details
		cout << "\t\t\t\t$" << (fl->get_flight()->get_price() + fl->get_flight()->getBaggageFees(num_bags)) << "\t\t";
		cout << "Base Price: $" << fl->get_flight()->get_price() << endl;

		delete temp;
		//advances the tracker
		fl = fl->get_next();
	}
	cout << "Number of Bags: " << num_bags << endl;
	//prints the price and time
	cout << "Total Price: $" << get_price(num_bags) << endl;
	cout << "Total Time: " << get_time() << " minutes." << endl;
}

Route::~Route()
{
	//clears all the flight node tracker objects from memory
	Iterator iter;
	iter.clear_list(flight_list);
}
//=====================================================================================================


//=====================================================================================================
Route *RouteList::get_current()			{return current;}
RouteList *RouteList::get_next()		{return next;}

void RouteList::set_current(Route *n)	{current = n;}
void RouteList::set_next(RouteList *n)	{next = n;}
//=====================================================================================================


//=====================================================================================================
void RouteListManipulator::remove_next(RouteList *p)
{
	p->set_next(p->get_next()->get_next());
}

void RouteListManipulator::set_to_head(RouteList *head, RouteList *p)
{
	RouteList *temp = head, *t;
	while(temp->get_next() != p)
	{
		temp = temp->get_next();
	}
	t = temp->get_next();
	remove_next(temp);
	t->set_next(head);
}

void RouteListManipulator::clear_data(RouteList *head)
{
	if(head)
	{
		clear_data(head->get_next());
		delete head->get_current();
		delete head;
	}
}
//=====================================================================================================