#include "Waiter.h"
#include "IdleState.h"
#include "OrderState.h"
#include <list>

//constructor for Waiter class
Waiter::Waiter()
{
	currentState = new IdleState(); // ensure that the currentState is set to idle when constructed 
	currentState->Enter(this); // make sure that the Enter function is called 
	isCustomerPresent = true; // set isCustomerPresent to true as default
}


Waiter::~Waiter()
{
}

// method called by main() in a while loop
void Waiter::Update()
{
// Using update to set customer to true at random intervals to keep the FSM looping round, while still accessing
// other states when isCustomerPresent is false
	if (!isCustomerPresent)
	{
		isCustomer = ((10-9)+1) * rand() / (RAND_MAX + 1.0);
		if (isCustomer <= 7)
			isCustomerPresent = true;
	}

	currentState->Execute(this);
	isCustomerPresent = false;
}


//////////////////////////////////////////////////////////////////////////////
// change state method makes use of the Enter and Exit functions			//
// and makes sure that the current state calls exit when it leaves the		//
// origin state, switches the state and then calls the enter function		//
// on the new state															//
//////////////////////////////////////////////////////////////////////////////

void Waiter::ChangeState(IBaseState * newState)
{
	currentState->Exit(this);
	currentState = newState;
	currentState->Enter(this);
}
