#include "FlightNode.h"

//Constructor
FlightNode::FlightNode(char flight_num[], char flight_comp[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest)
{
	strcpy(flightNumber, flight_num);
	strcpy(flightCompany, flight_comp);
	price = priceofflight;
	duration = durationofflight;
	next = NULL;
	departure = time;
	source = src;
	destination = dest;
}

//accessors
double		FlightNode::get_price()			{return price;}
int			FlightNode::get_duration()		{return duration;}
char*		FlightNode::get_flight_num()	{return flightNumber;}
char*		FlightNode::get_flight_comp()	{return flightCompany;}
FlightNode*	FlightNode::get_next()			{return next;}
Date_Time*	FlightNode::get_departure()		{return departure;}
HubNode*	FlightNode::get_source()		{return source;}
HubNode*	FlightNode::get_destination()	{return destination;}
	
//mutators
void FlightNode::set_next(FlightNode *n)		{next = n;}
void FlightNode::set_departure(Date_Time *time)	{departure = time;}



FlightSoutWest::FlightSoutWest(char flight_num[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest)
		: FlightNode(flight_num, "SouthWest", priceofflight, durationofflight, time, src, dest) {}

//calculates the appropriate baggage fees
//25 per bag
float FlightSoutWest::getBaggageFees(int num_bags) {return (float)(num_bags * 25);}

//calculates the delay
int FlightSoutWest::getDelay()
{
	if(7 <= get_departure()->get_hour() && 17 >= get_departure()->get_hour())
	{
		return 30;
	}
	else
	{
		return 0;
	}
}

FlightSoutWest *FlightSoutWest::clone()
{
	FlightSoutWest *new_flight = new FlightSoutWest(get_flight_num(), get_price(), get_duration(), get_departure()->copy(), get_source(), get_destination());
	return new_flight;
}


FlightUSAirway::FlightUSAirway(char flight_num[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest)
		: FlightNode(flight_num, "USAirway", priceofflight, durationofflight, time, src, dest) {}

//calculates the appropriate baggage fees
float FlightUSAirway::getBaggageFees(int num_bags)
{
	//checks to see if luggage fees will apply (2+ bags)
	if(num_bags > 1)
	{
		//subtracts the first one (free) and multiplys by 25
		return (float)((num_bags - 1) * 25);
	}
	//1 or 0 bags invokes no fees
	return 0;
}

//calculates the delay
int FlightUSAirway::getDelay()
{
	if(7 <= get_departure()->get_hour() && 17 >= get_departure()->get_hour())
	{
		return 30;
	}
	else if(17 < get_departure()->get_hour() || 1 >= get_departure()->get_hour())
	{
		return 15;
	}
	return 0;
}

FlightUSAirway *FlightUSAirway::clone()
{
	FlightUSAirway *new_flight = new FlightUSAirway(get_flight_num(), get_price(), get_duration(), get_departure()->copy(), get_source(), get_destination());
	return new_flight;
}


FlightDelta::FlightDelta(char flight_num[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest)
		: FlightNode(flight_num, "Delta", priceofflight, durationofflight, time, src, dest) {}

//calculates the appropriate baggage fees
//free baggage
float FlightDelta::getBaggageFees(int num_bags) {return 0.0;}

//calculates the delay
int FlightDelta::getDelay()
{
	return 20;
}

FlightDelta *FlightDelta::clone()
{
	FlightDelta *new_flight = new FlightDelta(get_flight_num(), get_price(), get_duration(), get_departure()->copy(), get_source(), get_destination());
	return new_flight;
}