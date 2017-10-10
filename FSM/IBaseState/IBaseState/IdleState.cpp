#include "IdleState.h"
#include "Waiter.h"
#include "OrderState.h"
#include "DeliverFState.h"


IdleState::IdleState()
{
}

IdleState::~IdleState()
{
}

void IdleState::Enter(Waiter * wait)
{
}

void IdleState::Execute(Waiter * wait)
{
	switch




	if (wait->isCustomerPresent = true)
	{
		wait->ChangeState(new OrderState());
	}
	else if (wait->isFoodCooked = true)
	{
		std::cout << "Have I got here?";
		wait->ChangeState(new DeliverFState());
	}

	//TODO condition to switch to clearTable state
}

void IdleState::Exit(Waiter * wait)
{
	
}

