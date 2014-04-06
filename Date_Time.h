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
	void add_hour(int hour);
	void add_day(int day);
	void add_month(int month);
	void add_year(int year);

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

	long get_min_since_2013();

	string get_time();

};//end of Date_Time class

#endif