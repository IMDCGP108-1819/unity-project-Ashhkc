#include "Waiter.h"


int main()
{
	Waiter* waiter = new Waiter();

	while (true)
	{
		waiter->Update();
	}

	return 0;
}