#include "IdleState.h"
#include "Waiter.h"
#include "OrderState.h"
#include "DeliverFState.h"
#include "ClearTable.h"

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
	if (wait->isCustomerPresent == true)
	{
		Sleep(1000);  // make program sleep for readability
		wait->ChangeState(new OrderState());
	}
	
	if (wait->isFoodCooked == true)
	{
		Sleep(1000);  // make program sleep for readability
		wait->ChangeState(new DeliverFState());
	}

	if (wait->isTableFinished == true)
	{
		Sleep(1000);  // make program sleep for readability
		wait->ChangeState(new ClearTable());
	}
}

void IdleState::Exit(Waiter * wait)
{
}

