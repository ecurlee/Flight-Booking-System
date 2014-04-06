#include <iostream>
#include "MainMenu.h"

using namespace std; //don't know if we're supposed to use std here
					 //or if he just wants it for itinerary

MainMenu::MainMenu(char choice)
{
	char select = choice; 

	std.cout << "WELCOME TO FLIGHT BOOKING SYSTEM" << endl;
	std.cout << setfill('-') << setw(80) << "-" << endl;
	std.cout << "Which of the following would you like to do?" <<endl;
	std.cout << "b: Book a flight" << endl;
	std.cout << "q: Quit" << endl;

	std.cin >> choice;

	QuitMenu *quitIt = new QuitMenu();

	switch (choice) {
	case "b": BookFlightMenu(); //gathers start, dest, date/time and spits out two options, make user choose
		break;
	case "q": delete quitIt; //this one should destruct the flight list
		break;
	default: cout << "Invalid choice. Try again." << endl;
		break;
	}




}