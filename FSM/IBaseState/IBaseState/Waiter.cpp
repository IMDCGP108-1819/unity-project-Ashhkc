#include "Waiter.h"
#include "IdleState.h"
#include "KitchenState.h"

Waiter::Waiter()
{
	currentState = new IdleState();
	currentState->Enter(this);
	isCustomerPresent = true;
}


Waiter::~Waiter()
{
}

void Waiter::Update()
{
	if (!isCustomerPresent)
	{
		isCustomer = ((10-9)+1) * rand() / (RAND_MAX + 1.0);
		if(isCustomer <= 7)
			isCustomerPresent = true;
	}
	
	currentState->Execute(this);
	isCustomerPresent = false;
}

void Waiter::ChangeState(IBaseState * newState)
{
	currentState->Exit(this);
	currentState = newState;
	currentState->Enter(this);
}
