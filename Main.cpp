#include <iostream>
#include <iomanip>
#include "SysMaker.h"
#include "Iterator.h"
#include "Navigator.h"
#include "Sort.h"

#define ISNUM(a) ((47 < a && a < 58) ? true : false)


SysMaker sys;
bool BookFlightMenu();
bool is_valid_num(char *num);
Date_Time *parse_time(string time);

void main()
{
	char choice = '\0'; 
	sys.build_hub_list();
	sys.build_flight_list();
	while('q' != choice)
	{
		cout << "WELCOME TO FLIGHT BOOKING SYSTEM" << endl;
		cout << "--------------------------------" << endl;
		cout << "Which of the following would you like to do?" <<endl;
		cout << "b: Book a flight" << endl;
		cout << "q: Quit" << endl;

		cin >> choice;

		switch (choice) 
		{
		case 'b': 
			//while the booking system is needed
			while(!BookFlightMenu()){}
			break;
		case 'q': 
			//exits the system
			cout << "\nGoodbye.";
			break;
		default: cout << "Invalid choice. Try again." << endl;
			break;
		}
	}
}

bool BookFlightMenu()
{
	Iterator iter;
	int num_bags, num_hops = -1;
	char nb[12], select = '\0';
	string source, destination, departure;
	Date_Time *dpt;
	HubNode *src, *dest;
	Navigator *navi;
	Sort *srt;
	RouteList *head = NULL;
	char buffer[100];
	
	cin.getline(buffer, 25);
	//prompts the user for the depatrue city
	cout << "\nWhat city are you departing from?" << endl;
	cin.getline(buffer, 100);
	source = buffer;
	//tries to find the city
	src = iter.find_loc(sys.get_head(), source);
	// IF isn't in list, return error message
	while(!src) { 
		cout << "City does not exist. Try again." << endl;
		cin.getline(buffer,100);
		source = buffer;
		src = iter.find_loc(sys.get_head(), source);
	}

	//prompts the user for the destination city
	cout << "\nWhat is your destination?" << endl;
	// IF isn't in list, return error message
	cin.getline(buffer,100);
	destination = buffer;
	//tries to find the destination
	dest = iter.find_loc(sys.get_head(), destination);
	while(!dest) { 
		cout << "City does not exist. Try again." << endl;
		cin.getline(buffer,100);
		destination = buffer;
		dest = iter.find_loc(sys.get_head(), destination);
	}

	//asks the user for the departure time
	cout << "\nWhen do you want to depart " << source << "? (Enter as: MM/DD/YYYY)" << endl;
	cin >> departure;
	//tries to parse the time
	dpt = parse_time(departure);
	while(!dpt)
	{
		cout << "Invalid input. Try again." << endl;
		cin >> departure;
		dpt = parse_time(departure);
	}

	//asks for the maximum number of hops
	cout << "\nWhat is the maximum number of hops that you would like to make?" << endl;
	cin >> num_hops;
	while(num_hops < 1)
	{
		cout << "Incorrect input" << endl;
		cin >> num_hops;
	}

	//asks for bags
	cout << "\nEnter the number of bags you are checking in." << endl;
	cin >> nb;
	//handles invalid input
	while(!is_valid_num(nb))
	{
		cout << "Invalid number entered. Try again." << endl;
		cin >> nb;
	}
	//converts to integer
	num_bags = atoi(nb);
	
	//makes a navigator
	navi = new Navigator(src, dest, dpt);
	navi->set_max(num_hops);
	head = navi->find_routes();
	//if no routes are found
	if(!head)
	{
		//cleans up
		delete navi;
		delete dpt;
		//displays error message
		cout << "\nCould not find any flights meeting criteria.\n\n" << endl;
		return false;
	}
	srt = new Sort(head, num_bags);

	cout << "\nWould you like to sort by n hops?" << endl;
	cout << "y: yes" << endl;
	cout << "n: no" << endl;
	cin >> select;
	//while input is invalid
	while('n' != select && 'y' != select)
	{
		cout << "Invalid input." << endl;
		cin >> select;
	}
	if('y' == select)
	{
		//asks for the number of hops
		cout << "\nHow many hops?" << endl;
		cin >> nb;
		//handles invalid input
		while(!is_valid_num(nb))
		{
			cout << "Invalid number entered. Try again." << endl;
			cin >> nb;
		}
		num_hops = atoi(nb);
		//prompts to display either the cheapest or shortest flight
		cout << "\np: Display cheapest flight." << endl;
		cout << "t: Display shortest flight." << endl;
		cin >> select;
		//while the input is not valid
		while('p' != select && 't' != select)
		{
			cout << "Invalid input." << endl;
			cout << "p: Display cheapest flight." << endl;
			cout << "t: Display shortest flight." << endl;
			cin >> select;
		}
		if('p' == select)
		{
			//dipslays the cheapest flight
			if(!srt->sort_by_price(num_hops))
			{
				//cleans up
				delete navi;
				delete dpt;
				delete srt;
				//displays error message
				cout << "\nCould not find any flights meeting criteria.\n\n" << endl;
				return false;
			}
			cout << "\nCheapest flight is:" << endl;
		}
		else
		{
			//dipslays the cheapest flight
			if(!srt->sort_by_time(num_hops))
			{
				//cleans up
				delete navi;
				delete dpt;
				delete srt;
				//displays error message
				cout << "\nCould not find any flights meeting criteria.\n\n" << endl;
				return false;
			}
			//displays the shortest flight
			cout << "\nShortest flight is:" << endl;
		}

	}
	else
	{
		//prompts to display either the cheapest or shortest flight
		cout << "\np: Display cheapest flight." << endl;
		cout << "t: Display shortest flight." << endl;
		cin >> select;
		//while the input is not valid
		while('p' != select && 't' != select)
		{
			cout << "Invalid input." << endl;
			cout << "p: Display cheapest flight." << endl;
			cout << "t: Display shortest flight." << endl;
			cin >> select;
		}
		if('p' == select)
		{
			//dipslays the cheapest flight
			cout << "\nCheapest flight is:" << endl;
			srt->sort_by_price();
		}
		else
		{
			//displays the shortest flight
			cout << "\nShortest flight is:" << endl;
			srt->sort_by_time();
		}
	}

	//prints the route
	head->get_current()->print_route(num_bags);

	//asks if the user wants to reserve the flight
	cout << "\nReserve this flight?" << endl;
	cout << "y: yes" << endl;
	cout << "n: no" << endl;
	cin >> select;
	//while input is invalid
	while('n' != select && 'y' != select)
	{
		cout << "Invalid input." << endl;
		cin >> select;
	}
	if('n' == select)
	{
		//tells the user that the flight was not booked
		cout << "Flight not booked.\n\n" << endl;
	}
	else
	{
		//tells the user that the flight was booked (it's lying)
		cout << "Flight booked.\n\n" << endl;
	}

	//clean up
	delete srt;
	delete navi;
	delete dpt;
	//process completed
	return true;
}

Date_Time *parse_time(string time)
{
	int mo, day, yr;
	char temp[5];
	try
	{
		//if the string is not of the correct length
		if(time.length() != 10)
		{
			throw false;
		}

		if('/' != time[2] || '/' != time[5])
		{
			throw false;
		}

		//initializes the 3 char to null
		temp[2] = '\0';

		//copies the chars for month
		if(!ISNUM(time[0]) || !ISNUM(time[1]))
		{
			throw false;
		}
		temp[0] = time[0];
		temp[1] = time[1];
		//converts to int
		mo = atoi(temp);

		//day
		if(!ISNUM(time[3]) || !ISNUM(time[4]))
		{
			throw false;
		}
		temp[0] = time[3];
		temp[1] = time[4];
		//converts to int
		day = atoi(temp);

		//year
		if(!ISNUM(time[6]) || !ISNUM(time[7]) || !ISNUM(time[8]) || !ISNUM(time[9]))
		{
			throw false;
		}
		temp[0] = time[6];
		temp[1] = time[7];
		temp[2] = time[8];
		temp[3] = time[9];
		temp[4] = '\0';
		//converts to int
		yr = atoi(temp);

		//checks the month and day input
		if(mo > 12 || day > 31 || mo < 1 || day < 1)
		{
			throw false;
		}
		switch(mo)
		{
		case 2:
			if(yr % 4 == 0)
			{
				if(day > 29)
				{
					throw false;
				}
			}
			else
			{
				if(day > 28)
				{
					throw false;
				}
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(day > 30)
			{
				throw false;
			}
			break;
		}
	}
	catch(bool t)
	{
		cout << "Incorrect format" << endl;
		return NULL;
	}

	//makes and returns a new date_time
	return new Date_Time(0, 0, day, mo, yr);
}

bool is_valid_num(char *num)
{
	//if the first char is a num
	if(ISNUM(*num))
	{
		num++;
		//while every subsequent char is a num
		while(ISNUM(*num))
		{
			//advance
			num++;
		}
		//if the null terminator is reached
		if('\0' == *num)
		{
			//then it contains only numbers
			return true;
		}
	}
	//otherwise it does not
	return false;
}