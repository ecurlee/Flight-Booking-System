#include "Route.h"
#include "RouteList.h"

#include "HubNode.h"
#include "FlightNode.h"
#include "Common.h"

//creates a linked list

Route::Route(FlightNode *flightlist, HubNode *start, HubNode *dest)
{
		//create list with starting flight as the head
	HubNode *flightlist = *head;
	HubNode *start;
	start = (HubNode*)malloc(sizeof(HubNode));


		//find last flight in list
	HubNode *temp;
	temp = (HubNode*)malloc(sizeof(HubNode));
	temp = head;
	while(temp->next != NULL)
     temp = temp->next;
		//add destination (end) as last node
	HubNode *dest;
	dest = (HubNode*)malloc(sizeof(HubNode));
	dest->next = NULL;
	temp->next = dest;

}

//accessors
FlightNode	*Route::get_flights()	
{
	return flightlist;
}

HubNode	Route::get_dest() {return destination;}
HubNode	Route::get_start() {return start;}
FlightNode Route::get_price() {return price;}
FlightNode Route::get_time() {return time;}


int num_flights() {return sizeOf(flightlist);}; //# of flights in the route (# of hops)



