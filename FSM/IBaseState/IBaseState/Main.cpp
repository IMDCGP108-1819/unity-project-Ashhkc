// Defines the entry point for the application.

#include "Waiter.h"


int main()
{
	Waiter* waiter = new Waiter();

	while (true)
	{
		waiter->Update(); //Updates the FSM every loop through the while statement
	}

	return 0;
}