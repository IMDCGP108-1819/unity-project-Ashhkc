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
		isCustomer = rand() % 20 + 1;
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
