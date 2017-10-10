#include "KitchenState.h"
#include "IdleState.h"
#include "Waiter.h"


KitchenState::KitchenState()
{
}

KitchenState::~KitchenState()
{
}

void KitchenState::Enter(Waiter * wait)
{
	std::cout << "Got a new order for you!" << std::endl;
	wait->isCustomerPresent = false;
}

void KitchenState::Execute(Waiter * wait)
{
	wait->ChangeState(new IdleState());
}

void KitchenState::Exit(Waiter * wait)
{
	std::cout << "Now to wait for the next command... (-> IdleState)" << std::endl;
	wait->isFoodCooked = true;
}
