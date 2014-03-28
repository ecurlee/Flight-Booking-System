#ifndef FlightNode_h
#define FlightNode_h

#include "Common.h"
#include "HubNode.h"
#include "Date_Time.h"

class FlightNode
{
private:
	char flightNumber[8];
	char flightCompany[12];
	double price;
	int duration;
	Date_Time *departure;
	HubNode *source;
	HubNode *destination;
	FlightNode *next;
	
public:
	//to be implemented in the sub classes
	virtual float getBaggageFees(){return (-1.0);};
	virtual int getDelay(){return (-1);};
	virtual FlightNode *clone(){return NULL;};
	//Constructor
	FlightNode(char flight_num[], char flight_comp[], double priceofflight, int durationofflight, Date_Time *dt, HubNode *src, HubNode *dest);

	//accessors
	double get_price();
	int get_duration();
	char *get_flight_num();
	char *get_flight_comp();
	FlightNode *get_next();
	Date_Time *get_departure();
	HubNode *get_source();
	HubNode *get_destination();
	
	//mutator
	void set_next(FlightNode *n);
	void set_departure(Date_Time *time);
};

class FlightSoutWest : public FlightNode
{
public:
	FlightSoutWest(char flight_num[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest);

	//calculates the appropriate baggage fees
	//25 per bag
	float getBaggageFees(int num_bags);

	//calculates the delay
	int getDelay();

	FlightSoutWest *clone();
};

class FlightUSAirway : public FlightNode
{
public:
	FlightUSAirway(char flight_num[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest);

	//calculates the appropriate baggage fees
	float getBaggageFees(int num_bags);

	//calculates the delay
	int getDelay();

	FlightUSAirway *clone();
};

class FlightDelta : public FlightNode
{
public:
	FlightDelta(char flight_num[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest);

	//calculates the appropriate baggage fees
	//free baggage
	float getBaggageFees(int num_bags);

	//calculates the delay
	int getDelay();
	FlightDelta *clone();
};

#endif