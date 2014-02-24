#include <stdio.h>
#include <stdlib.h>
#include <string>

#define FLIGHT_NUM_CHAR 10
#define FLIGHT_COMP_CHAR 15

class FlightNode
{
	private:
		char flightNumber[FLIGHT_NUM_CHAR], flightCompany[FLIGHT_COMP_CHAR];
		//Date_Time departure
		double price;
		int duration;
		//HubNode *source, *destination;
		FlightNode *next;

	public:
		//to be implemented in the sub classes
		virtual float getBaggageFees() {}
		virtual int getDelay() {}

		//Constructor
		FlightNode(char flight_num[], char flight_comp[], double priceofflight, int durationofflight)
		{
			strcpy(flightNumber, flight_num);
			strcpy(flightCompany, flight_comp);
			price = priceofflight;
			duration = durationofflight;
			
		}

		//returns the price of the flight
		double get_price() {return price;}

		//returns the duration of the flight
		int get_duration() {return duration;}

		/*
		Date_Time get_departure() {eturn departure;}

		HubNode *get_source() {return source;}

		HubNode *get_destination() {return destination;}
		*/

		//returns the next flight in the list
		FlightNode *get_next() {return next;}
};

class FlightSoutWest : public FlightNode
{
	public:
		FlightSoutWest(char flight_num[], char flight_comp[], double priceofflight, int durationofflight)
			: FlightNode(flight_num[], flight_comp[], priceofflight, durationofflight) {}

		//calculates the appropriate baggage fees
		//25 per bag
		float getBaggageFees(int num_bags) {return (num_bags * 25);}

		//calculates the delay
		int getDelay()
		{
			/*
			if(700 <= get_departure() && 1700 >= get_departure())
			{
				return 30;
			}
			else
			{
				return 0;
			}
			*/
			return -1;
		}
};

class FlightUSAirway : public FlightNode
{
	public:
		FlightUSAirway(char flight_num[], char flight_comp[], double priceofflight, int durationofflight)
			: FlightNode(flight_num[], flight_comp[], priceofflight, durationofflight) {}

		//calculates the appropriate baggage fees
		float getBaggageFees(int num_bags)
		{
			//checks to see if luggage fees will apply (2+ bags)
			if(num_bags > 1)
			{
				//subtracts the first one (free) and multiplys by 25
				return ((num_bags - 1) * 25);
			}
			//1 or 0 bags invokes no fees
			return 0;
		}

		//calculates the delay
		int getDelay()
		{
			/*
			if(700 <= get_departure() && 1700 >= get_departure())
			{
				return 30;
			}
			else if(1700 < get_departure() || 1 >= get_departure()
			{
				return 15;
			}
			return 0;
			*/
			return -1;
		}
};

class FlightDelta : public FlightNode
{
	public:
		FlightDelta(char flight_num[], char flight_comp[], double priceofflight, int durationofflight)
			: FlightNode(flight_num[], flight_comp[], priceofflight, durationofflight) {}

		//calculates the appropriate baggage fees
		//free baggage
		float getBaggageFees(int num_bags) {return 0.0;}

		//calculates the delay
		int getDelay()
		{
			return 20;
		}
};