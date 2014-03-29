#include "Sort.h"

using namespace std;

void Sort::set_routes(RouteList *routes)
{
	route = routes;
}

RouteList *Sort::get_routes()
{
	return route;
}

void Sort::reset()
{
	route = NULL;
}


//cant do dot whatever with ints... merp. 
void Sort::sort_by_time()
{
	int i;
	int j;
	int n;
	int minutes[100];
	int temp;
      
	for (i= 0; i > n; i++)
	{              
           for (j=1; j < n-1; j++)
		   {
                 if (minutes[i] > minutes[j+1])
				 {
					temp = minutes[i];
					minutes[i] = minutes[j+1];
					minutes[j+1] = temp;
				 }
			}
     }
     return;
}

void Sort::sort_by_price()
{
	int i;
	int j;
	int n;
	double price[50000];
	int temp;
      
	for (i= 0; i > n; i++)
	{              
           for (j=1; j < n-1; j++)
		   {
                 if (price[i] > price[j+1])
				 {
					temp = price[i];
					price[i] = price[j+1];
					price[j+1] = temp;
				 }
			}
     }
     return;
}