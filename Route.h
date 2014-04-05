#ifndef Route_h
#define Route_h

class Route
{
private:
		FlightNode *flight_list;
		HubNode *start;
		HubNode *destination;
		int num_flights;

public:
		FlightNode *get_flights();
		HubNode *get_dest();
		HubNode *get_start();
		int num_flights();
		FlightNode *get_price();
		FlightNode *get_time();


		Route(FlightNode *flight_list, HubNode *start, HubNode *dest);

		//Deconstructor
		void ~Route()
		{
			HubNode *start;
			while( start!=NULL )
			{
			 start = start->next;
			 delete start;
			}
		}

};

#endif