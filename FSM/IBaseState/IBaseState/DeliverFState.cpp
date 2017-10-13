#include "Waiter.h"
#include "DeliverFState.h"
#include "IdleState.h"


DeliverFState::DeliverFState()
{
}


DeliverFState::~DeliverFState()
{
}

void DeliverFState::Enter(Waiter * wait)
{
	std::cout << "Food's ready" << std::endl;
	wait->isFoodCooked = false;
}

void DeliverFState::Execute(Waiter * wait)
{
	std::cout << "Here is your food." << std::endl;
	Sleep(1000);
	wait->ChangeState(new IdleState());
}

void DeliverFState::Exit(Waiter * wait)
{
	std::cout << "Now to wait for the next command..." << std::endl;
}
