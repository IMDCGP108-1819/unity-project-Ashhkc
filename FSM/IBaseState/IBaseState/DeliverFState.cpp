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
	wait->isFoodCooked = false;
	std::cout << "Here's your food...";
	Sleep(1000);
}

void DeliverFState::Execute(Waiter * wait)
{
	wait->ChangeState(new IdleState());
	Sleep(1000);
}

void DeliverFState::Exit(Waiter * wait)
{
	foodReference++;
	wait->isTableFinished = true;
	std::cout << " can I get you anything else? " << std::endl;
	std::cout << "Food delivered to customer: " << foodReference << std::endl << std::endl;
}
