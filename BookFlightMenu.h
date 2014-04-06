#ifndef BookFlightMenu_h
#define BookFlightMenu_h

#include "HubNodeIterator.h"
#include "Navigator.h"
#include "FlightNode.h"
#include "FlightTrackerIterator.h"
#include "FlightNode.h"

class BookFlightMenu
{

private:
	Date_Time *departure;
	HubNode *source;
	HubNode *destination;
	FlightNode *number_bags;


public:
	//constructor 
	BookFlightMenu(int date1, int date2, char start, char end, int num_bags);
	float getBaggageFees();


};

class PrintItinerary : public BookFlightMenu
{
public:
	PrintItinerary(char flight_num[], char flight_comp[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest, int num_bags);

};

#endif