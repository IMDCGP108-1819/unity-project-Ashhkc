#include "KitchenState.h"
#include "IdleState.h"
#include "Waiter.h"

//////////////////////////////////////////////////////////////////
//	Basic kitchen class, doesnt output anything to the console, //
//	used to update boolean values behind the scenes.			//
//////////////////////////////////////////////////////////////////

KitchenState::KitchenState()
{
}

KitchenState::~KitchenState()
{
}

void KitchenState::Enter(Waiter * wait)
{
	wait->isCustomerPresent = false;
}

void KitchenState::Execute(Waiter * wait)
{
	wait->ChangeState(new IdleState());
}

void KitchenState::Exit(Waiter * wait)
{
	wait->isFoodCooked = true;
}
