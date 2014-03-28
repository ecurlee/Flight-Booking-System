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
	void Date_Time::add_hour(int hour);
	void Date_Time::add_day(int day);
	void Date_Time::add_month(int month);
	void Date_Time::add_year(int year);

public:
	//Constructor
	Date_Time(int min, int hour, int day, int month, int year);

	//accessors
	int get_min();
	int get_hour();
	int get_day();
	int get_month();
	int get_year();

	void add_min(int min);
	Date_Time *copy();
	

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