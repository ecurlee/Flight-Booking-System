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

void Date_Time::add_min(int min)
{
	minutes += min;
	if(minutes > 59)
	{
		add_hour(minutes / 60);
		minutes %= 60;
	}
}

void Date_Time::add_hour(int hour)
{
	hours += hour;
	if(hours > 23)
	{
		add_day(hour / 24);
		hours %= 24;
	}
}

void Date_Time::add_day(int day)
{
	days += day;
	switch(months)
	{
	case 1:
		if(days > 31)
		{
			add_month(1);
			months %= 31;
		}
		break;
	case 2:
		if(years % 4 == 0)
		{
			if(days > 29)
			{
				add_month(1);
				months %= 29;
			}
		}
		else
		{
			if(days > 28)
			{
				add_month(1);
				months %= 28;
			}
		}
		break;
	case 3:
		if(days > 31)
		{
			add_month(1);
			months %= 31;
		}
		break;
	case 4:
		if(days > 30)
		{
			add_month(1);
			months %= 30;
		}
		break;
	case 5:
		if(days > 31)
		{
			add_month(1);
			months %= 31;
		}
		break;
	case 6:
		if(days > 30)
		{
			add_month(1);
			months %= 30;
		}
		break;
	case 7:
		if(days > 31)
		{
			add_month(1);
			months %= 31;
		}
		break;
	case 8:
		if(days > 31)
		{
			add_month(1);
			months %= 31;
		}
		break;
	case 9:
		if(days > 30)
		{
			add_month(1);
			months %= 30;
		}
		break;
	case 10:
		if(days > 31)
		{
			add_month(1);
			months %= 31;
		}
		break;
	case 11:
		if(days > 30)
		{
			add_month(1);
			months %= 30;
		}
		break;
	case 12:
		if(days > 31)
		{
			add_month(1);
			months %= 31;
		}
		break;
	}
}

void Date_Time::add_month(int month)
{
	months += month;
	if(months > 12)
	{
		add_year(months / 12);
		months %= 12;
	}
}

void Date_Time::add_year(int year)
{
	years += year;
}

Date_Time *Date_Time::copy()
{
	Date_Time *newDT = new Date_Time(minutes, hours, days, months, years);
	return newDT;
}