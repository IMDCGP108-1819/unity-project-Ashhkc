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
	
	std::cout << "iscustomerpresent is " << wait->isCustomerPresent << std::endl;

	if (wait->isCustomerPresent == true)
	{
		Sleep(1000);
		wait->ChangeState(new OrderState());
	}
	
	if (wait->isFoodCooked == true)
	{
		std::cout << "Have I got here?" << std::endl;
		Sleep(1000);
		wait->ChangeState(new DeliverFState());
	}

	//TODO condition to switch to clearTable state
}

void IdleState::Exit(Waiter * wait)
{
	
}

