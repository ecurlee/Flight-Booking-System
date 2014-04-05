#include "BookFlightMenu.h"


BookFlightMenu::BookFlightMenu(int date1, int date2, char start, char end)
{
	int departure = date1, date2;
	char source = start;
	char destination = end;

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


	// Information needs to be stored. Must create possible routes. Must sort them.
	// Must print the shortest, then the cheapest. Calculate baggage fees AND duration for shortest and cheapest routes.
	// PRINT info for shortest and cheapest. Ask user which one they want to do. Take user input. Print itinerary of 
	// the chosen flight. Say thanks, go back to MainMenu();

	// QuitMenu needs to be created. This one destructs.
}	
PrintItinerary::PrintItinerary(char flight_num[], char flight_comp[], double priceofflight, int durationofflight, Date_Time *time, HubNode *src, HubNode *dest)
	{
		cout << "Summary of your flight" << endl;

		char start, end;
		int time1, time2, date1, date2;
		cout << flight_num[start];
		cout << flight_comp[start];
		cout << start;
		cout << date1;
		cout << time;


	}