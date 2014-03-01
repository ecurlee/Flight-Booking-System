#include <iostream>
#include <fstream>
#include <string>

class HubNode
{
	private:
		char name, location;
		HubNode *next;

	public:
		HubNode(char nameOfHub[], char locationOfHub[])
		{
			strcpy(name, nameOfHub);
			strcpy(location, locationOfHub);
		}

		HubNode *get_next() {return next;}

		FlightNode *headFlight() {return head;}

		//unsure about this part

		fstream importData;
		importData.open("Hub.csv", ios::in | ios::binary); //open file for reading
		if(importData.is_open())
		{
		}
}