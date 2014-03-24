#include "SysMaker.h"

void main()
{
	int number = 0;
	SysMaker *sm = new SysMaker();
	sm->build_hub_list();
	sm->build_flight_list();
	sm->debug_print();
	delete sm;
	number++;
}