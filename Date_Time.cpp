
#include <iostream>
#include <string>


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


	Date_Time(int min, int hour, int day, int month, int year){
		minutes = min;
		hours = hour;
		days = day;
		months = month;
		years = year;
	}	

	void AddMinutes(int min){
		
	}

/****************************************************************************************************


typedef enum{
	Sun = 0, Mon, Tue, Wed, Thu, Fri, Sat
}day;

typedef enum{
	Jan = 0, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
}month;



*******************************************************************************************************/


};//end of Date_Time class