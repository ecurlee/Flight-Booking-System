#include "Date_Time.h"

using namespace std;

//Constructor
Date_Time::Date_Time(int min, int hour, int day, int month, int year){
	minutes = min;
	hours = hour;
	days = day;
	months = month;
	years = year;
}	

	
void Date_Time::AddMinutes(int min)
{
	minutes = (min >= 0 && min < 60) ? min : 0;
}