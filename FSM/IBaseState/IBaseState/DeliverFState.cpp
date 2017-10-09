#include "stdafx.h"
#include "DeliverFState.h"


DeliverFState::DeliverFState()
{
}


DeliverFState::~DeliverFState()
{
}

void DeliverFState::Enter(Waiter * wait)
{
	std::cout << "Food's ready" << std::endl;
}

void DeliverFState::Execute(Waiter * wait)
{
	std::cout << "Here is your food." << std::endl;
}

void DeliverFState::Exit(Waiter * wait)
{
	std::cout << "Now to wait for the next command..." << std::endl;
}
