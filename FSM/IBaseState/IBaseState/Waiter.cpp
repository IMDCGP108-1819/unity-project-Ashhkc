#include "Waiter.h"
#include "IdleState.h"
#include "KitchenState.h"

Waiter::Waiter()
{
	currentState = new IdleState();
	currentState->Enter(this);
}


Waiter::~Waiter()
{
}

void Waiter::Update()
{
	if (!isCustomerPresent)
	{
		sleep_for(2s);
		isCustomerPresent = true;
	}
	else if (isFoodCooked)
	{
		sleep_for(10s);
		isFoodCooked = true;
	}
	

	currentState->Execute(this);
}

void Waiter::ChangeState(IBaseState * newState)
{
	currentState->Exit(this);
	currentState = newState;
	currentState->Enter(this);
}
