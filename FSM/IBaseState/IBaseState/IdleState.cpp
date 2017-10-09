#include "IdleState.h"
#include "Waiter.h"
#include "OrderState.h"


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
	if (wait->IsCustomerPresent())
	{
		std::cout << "A new customer! (->TakeOrderState)" << std::endl;
		wait->ChangeState(new OrderState());
	}

	//TODO condition to switch to deliverFood state

	//TODO condition to switch to clearTable state
}

void IdleState::Exit(Waiter * wait)
{
	
}

