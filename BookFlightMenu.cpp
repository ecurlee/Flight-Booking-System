#include "BookFlightMenu.h"


BookFlightMenu::BookFlightMenu(int date1, int date2, char start, char end, int num_bags)
{
	int departure = date1, date2;
	char source = start;
	char destination = end;
	int number_bags = num_bags;

	cout << "What city are you departing from?" << endl;
	cin >> start;
	// IF isn't in list, return error message
	if (HubNodeIterator::find(head, start) == NULL) { //not sure if this is how i use the find method in HubNodeIterator to check if flight exists
		cout << "City does not exist. Try again." << endl;
		cin >> start;
	}

	cout << "What is your destination?" << endl;
	// IF isn't in list, return error message
	cin >> end;
	if (HubNodeIterator::find(head, start) == NULL) { //not sure if this is how i use the find method in HubNodeIterator to check if flight exists
		cout << "City does not exist. Try again." << endl;
		cin >> end;
	}
	cout << "When do you want to depart" << start << "? (Enter as: MM/DD/YYYY)" << endl;
	cin >> date1;
	cout << "When do you want to arrive" << end << "?" << endl;
	cin >> date2;
	// IF date is invalid, return error message
	// Use Navigator procedure called comp_Time to check if date is valid
	if (Navigator::comp_Time(date1, date2) == -1) {
		cout << "Dates are invalid. Please try again..." << endl;
		cout << "When do you want to depart" << start << "? (Enter as: MM/DD/YYYY)" << endl;
		cin >> date1;
		cout << "When do you want to arrive" << end << "?" << endl;
		cin >> date2;
	}

	cout << "Flights available at these times" << endl;

	//Creates possible routes with given information
	Route(FlightNode *flightlist, HubNode *start, HubNode *end);
	Route *myRoutePtr = new Route();
	Route myRoute;


	//Sorts routes by shortest
	myRoute.sort_by_time();

	//Print shortest (the head node of the list)
	cout << "Your shortest flight option:" << endl;
		//NEED TO DO

	//Sorts routes by cheapest
	myRoute.sort_by_price();

	//Print cheapest (the head node of the list)
	cout << "Your cheapest flight option:" << endl;
		//NEED TO DO
	
	cout << "Would you like to pick the shortest flight option or the cheapest flight option?" << endl;
	cout << "a: shortest" << endl;
	cout << "b: cheapest" << endl;
	
	switch (choice) {
	case "a": myRoute.sort_by_time();
		break;
	case "b": myRoute.sort_by_price(); 
		break;
	default: cout << "Invalid choice. Try again." << endl;
		break;
	}

	myRoute.get
		


	cout << "Enter total number of bags you with to check in" << endl;
	cin >> num_bags;
	FlightNode *bags = new FlightNode();
	bags -> getBaggageFees();



}	
PrintItinerary::PrintItinerary(char flight_num[], char flight_comp[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest, int num_bags)
	{
		cout << "Summary of your flight" << endl;

		char start, end;
		int time1, time2, date1, date2;
		cout << flight_num[start];
		cout << flight_comp[start];
		cout << start;
		cout << date1;
		cout << time1 << endl;
		cout << flight_num[end];
		cout << flight_comp[end];
		cout << end;
		cout << date2;
		cout << time2 << endl;

		cout << "Check-in " << num_bags << " bags" << endl;

		//need to format...
		//need to calculate total



	}