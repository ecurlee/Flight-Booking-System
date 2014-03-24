#ifndef Date_Time_h
#define Date_Time_h

#include "Common.h"
class Date_Time{

private:
	int minutes;
	int hours;
	int days;
	int months;
	int years;

public:
	//Constructor
	Date_Time(int min, int hour, int day, int month, int year);

	//accessors
	int get_min();
	int get_hour();
	int get_day();
	int get_month();
	int get_year();
	

enum
{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
}month;

enum
{
	Sunday = 0, Monday, Tuesday, Thursday, Friday, Saturday
}day;

};//end of Date_Time class

#endif