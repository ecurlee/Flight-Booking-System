#include "Navigator.h"

Navigator::Navigator()
{
	start = NULL;
	dest = NULL;
	max_hops = 4;
	min_hops = 0;
}

Navigator::Navigator(HubNode *startn, HubNode *destn)
{
	start = startn;
	dest = destn;
	max_hops = 4;
	min_hops = 0;
}

void Navigator::reset()
{
	start = NULL;
	dest = NULL;
	max_hops = 4;
	min_hops = 0;
}

//accessors
void Navigator::set_dest(HubNode *destn)	{dest = destn;}
void Navigator::set_start(HubNode *startn)	{start = startn;}
void Navigator::set_max(int max)			{max_hops = max;}
void Navigator::set_min(int min)			{min_hops = min;}

//mutators
HubNode *Navigator::get_dest()	{return dest;}
HubNode *Navigator::get_start()	{return start;}
int Navigator::get_max()		{return max_hops;}
int Navigator::get_min()		{return min_hops;}

RouteList *Navigator::find_routes()
{

}

FlightNode *Navigator::copy_list(FlightNode *source)
{
	FlightNode *copy = NULL;
	FlightNode *start = NULL;
	if(source)
	{
		copy = source->clone();
		start = copy;
		source = source->get_next();
		while(source)
		{
			copy->set_next(source->clone());
			copy = copy->get_next();
			source = source->get_next();
		}
	}
	return start;
}

//returns 1 if dt1 is > dt2, 0 if dt1 == dt2, and -1 if dt1 < dt2
int Navigator::comp_time(Date_Time *dt1, Date_Time *dt2)
{
	int total = 0;
	//checks each variable starting at year to see if one is greater than the other
	if(dt1->get_year() > dt2->get_year())
		return 1;
	else if(dt1->get_year() < dt2->get_year())
		return -1;
	if(dt1->get_month() > dt2->get_month())
		return 1;
	else if(dt1->get_month() < dt2->get_month())
		return -1;
	if(dt1->get_day() > dt2->get_day())
		return 1;
	else if(dt1->get_day() < dt2->get_day())
		return -1;
	if(dt1->get_hour() > dt2->get_hour())
		return 1;
	else if(dt1->get_hour() < dt2->get_hour())
		return -1;
	if(dt1->get_min() > dt2->get_min())
		return 1;
	else if(dt1->get_min() < dt2->get_min())
		return -1;
	return 0;
}


void Navigator::set_head(HubNode *h)
{
	hnhead = h;
}

void Navigator::flood(FlightNode *path, int num_hops)
{
	if(num_hops > 0)
	{
		FlightNode *temp = path;
		HubNode *cur_loc;
		Date_Time *cur_time;
		Date_Time *cur_time_temp;
		HubNodeIterator hni;
		while(temp->get_next())
		{
			temp = temp->get_next();
		}
		cur_loc = hni.find(hnhead, temp->get_destination()->get_name());
		cur_time = temp->get_departure()->copy();
		cur_time->add_min(temp->get_duration());

		temp = cur_loc->headFlight();
		while(temp)
		{
			if(1 == comp_time(temp->get_departure(), cur_time))
			{
				cur_time_temp = cur_time->copy();
				cur_time_temp->add_min(temp->getDelay());
				if(-1 != comp_time(temp->get_departure(), cur_time_temp))
				{
					FlightNode *newList = copy_list(path);
					FlightNodeIterator fni;
					fni.add(&newList, temp->clone());
					if(0 == strcmp(temp->get_destination()->get_name(), dest->get_name()))
					{
					}
					else
					{
						flood(newList, num_hops - 1);
						delete newList;
					}
				}
				delete cur_time_temp;
			}
		}
		delete cur_time;
		/*
		if(0 == strcmp(dest->get_name(), temp->get_destination()->get_name()))
		{
		}
		*/
	}
}