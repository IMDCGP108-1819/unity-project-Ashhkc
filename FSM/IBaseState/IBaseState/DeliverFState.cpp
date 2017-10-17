#include "Waiter.h"
#include "DeliverFState.h"
#include "IdleState.h"

int DeliverFState::foodDelivered = 0; // count which customer has recieved their food

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
	foodDelivered++;
	wait->isTableFinished = true;
	std::cout << " can I get you anything else? " << std::endl;
	std::cout << "Food delivered to customer: " << foodDelivered << std::endl << std::endl;
}
