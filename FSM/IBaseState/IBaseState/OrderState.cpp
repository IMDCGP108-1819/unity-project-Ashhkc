#include "OrderState.h"
#include "Waiter.h"
#include "KitchenState.h"

OrderState::OrderState()
{
	
}

OrderState::~OrderState()
{
}

void OrderState::Enter(Waiter * wait)
{
	std::cout << "Hello, may I take your order?" << std::endl;
	Sleep(2000);
}

void OrderState::Execute(Waiter * wait)
{
	wait->ChangeState(new KitchenState());
}

void OrderState::Exit(Waiter * wait)
{
	customerReference++;
	std::cout << "Is that everything?  Great, I'll just put that through for you!" << std::endl;
	std::cout << "Customer number: " << customerReference << std::endl << std::endl;
	Sleep(1000);
}

