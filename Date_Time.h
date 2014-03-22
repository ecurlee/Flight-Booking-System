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
	Date_Time();
	void AddMinutes();
	char ToString();


	//Constructor
	Date_Time(int min, int hour, int day, int month, int year);

	
	void AddMinutes(int min);
	

enum{
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
}month;

};//end of Date_Time class

#endif