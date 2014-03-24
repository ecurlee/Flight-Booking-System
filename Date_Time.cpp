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

//accessors
int Date_Time::get_min()	{return minutes;}
int Date_Time::get_hour()	{return hours;}
int Date_Time::get_day()	{return days;}
int Date_Time::get_month()	{return months;}
int Date_Time::get_year()	{return years;}