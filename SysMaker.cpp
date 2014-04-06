#include "SysMaker.h"


//hubs------------------------------------------------------------------------------------
//makes the hub list
void SysMaker::build_hub_list()
{
	//used to store the name and location strings
	char name[80], loc[80];
	//used for making new nodes
	HubNode *temp;
	//used to iterate through the list (adding)
	Iterator iter;
	fstream fin;
	//opens the file
	fin.open("Hub.csv", ios::in | ios::binary);
	//if success
	if(fin.is_open())
	{
		//skips the first line
		fin.getline(name, 79, '\n');
		//reads the first name
		fin.getline(name, 60, ',');
		//while the end has not been reached
		while(name[0] != EOF && name[0] != NULL)
		{
			int i;
			//reads the location
			fin.getline(loc, 20, '\n');
			//used because a bug occurs with the '\r' char
			i = strlen(loc) - 1;
			if(32 > loc[i])
			{
				loc[i] = '\0';
			}

			//makes a new node
			temp = new HubNode(name, loc);
			//adds it
			iter.add(&hnhead, temp);

			//gets the next name
			fin.getline(name, 60, ',');
		}
		//closes the file
		fin.close();
	}
	//prints an error message
	else
	{
		cout << "ERROR: Could not open Hub.csv file!" << endl;
	}
}

//removes the hub list
void SysMaker::del_hl(HubNode *n)
{
	if(n)
	{
		del_hl(n->get_next());
		delete n;
	}
}

//prints the hub list
void SysMaker::print_hl(HubNode *n)
{
	if(n)
	{
		FlightNode *p = n->headFlight();
		cout << "\nName: " << n->get_name() << "\nLocation: " << n->get_location() << endl;
		while(p)
		{
			cout << "\nFlight Number: " << p->get_flight_num();
			p = p->get_next();
		}
		cout << "\n\n";
		print_hl(n->get_next());
	}
}

void SysMaker::del_hub_list()
{
	del_hl(hnhead);
}

void SysMaker::print_hub_list()
{
	print_hl(hnhead);
}

//Flights---------------------------------------------------------------------------------------------
void SysMaker::build_flight_list()
{
	char number[8], price[8], source[56], dest[56],  duration[4], company[12], garbage[400];
	char dep_m[4], dep_h[4], dep_d[4], dep_mo[4], dep_y[8];
	FlightNode *temp;
	Iterator iter;
	double pri;
	int dur, d_m, d_h, d_d, d_mo, d_y;
	HubNode *destNode, *srcNode;
	Date_Time *time;
	fstream fin;
	//opens the file
	fin.open("Flight.csv", ios::in | ios::binary);

	//if success
	if(fin.is_open())
	{
		int i;
		//skips the first line
		fin.getline(garbage, 400, '\n');
		//reads the first number
		fin.getline(number, 8, ',');
		while(number[0] != EOF && number[0] != NULL)
		{
			//reads the line of information
			fin.getline(price, 8, ',');
			fin.getline(source, 56, ',');
			fin.getline(dest, 56, ',');
			fin.getline(dep_m, 4, '/');
			fin.getline(dep_h, 4, '/');
			fin.getline(dep_d, 4, '/');
			fin.getline(dep_mo, 4, '/');
			fin.getline(dep_y, 8, ',');
			fin.getline(duration, 4, ',');
			fin.getline(company, 12, '\n');
			//used because a bug occurs with the '\r' char
			i = strlen(company) - 1;
			if(32 > company[i])
			{
				company[i] = '\0';
			}
			
			//converts the price
			pri = atof(price);

			//converts the strings to integers for the date
			d_m = atoi(dep_m);
			d_h = atoi(dep_h);
			d_d = atoi(dep_d);
			d_mo = atoi(dep_mo);
			d_y = atoi(dep_y);
			//makes the date
			time = new Date_Time(d_m, d_h, d_d, d_mo, d_y);

			//converts the duration
			dur = atoi(duration);

			//gets the source and destination nodes
			srcNode = iter.find_name(hnhead, source);
			destNode = iter.find_name(hnhead, dest);

			//makes a flight of the appropriate company
			if(0 == strcmp(company, "SouthWest"))
			{
				temp = new FlightSoutWest(number, pri, dur, time, srcNode, destNode);
			}
			else if(0 == strcmp(company, "USAirway"))
			{
				temp = new FlightUSAirway(number, pri, dur, time, srcNode, destNode);
			}
			else
			{
				temp = new FlightDelta(number, pri, dur, time, srcNode, destNode);
			}
			//adds it to the hub
			srcNode->add_flight(temp);

			//adds it to the flightnodetrackerlist

			//gets the next name
			fin.getline(number, 8, ',');
		}
		//closes the file
		fin.close();
	}
	//prints an error message
	else
	{
		cout << "ERROR: Could not open Flight.csv file!" << endl;
	}
}

void SysMaker::debug_print()
{
	print_hub_list();
}


SysMaker::~SysMaker()
{
	del_hub_list();
}