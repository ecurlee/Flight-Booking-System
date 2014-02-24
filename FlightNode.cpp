#include <stdio.h>

#define FLIGHT_NUM_CHAR 10
#define FLIGHT_COMP_CHAR 15

class FlightNode
{
	public:
		virtual float getBaggageFees();
		virtual int getDelay();
	private:
		char flightNumber[FLIGHT_NUM_CHAR], flightCompany[FLIGHT_COMP_CHAR];
		//Date_Time departure
		double price;
		int duration;
		//HubNode *source, *destination;
		FlightNode *next;
};

