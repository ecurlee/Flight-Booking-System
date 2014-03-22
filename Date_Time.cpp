#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;


//This isn't much of an edit but I think I have the right idea? Probably?


class Date_Time{

private:
	int minutes;
	int hours;
	int days;
	int months;
	int years;

public:
	Date_Time();
	void AddMinutes();
	char ToString();


	//Constructor
	Date_Time(int min, int hour, int day, int month, int year){
		minutes = min;
		hours = hour;
		days = day;
		months = month;
		years = year;
	}	


	void AddMinutes(int min){
		minutes = (min >= 0 && min < 60) ? min : 0;
	}


enum{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
}month;

	if(month >= 13){
		cout << "Error" << endl;
	}
	else{
		return month;
	}



};//end of Date_Time class