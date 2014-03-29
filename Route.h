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