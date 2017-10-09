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
		wait->ChangeState(new OrderState());
	}
}

void IdleState::Exit(Waiter * wait)
{
	std::cout << "A new customer!" << std::endl;
}

