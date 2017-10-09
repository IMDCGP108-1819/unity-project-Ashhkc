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
	std::cout << "It's hot in the kitchen!" << std::endl;
}

void KitchenState::Execute(Waiter * wait)
{
	wait->ChangeState(new IdleState());
}

void KitchenState::Exit(Waiter * wait)
{
	std::cout << "Now to wait for the next command..." << std::endl;
	wait->isFoodCooked = true;
}
