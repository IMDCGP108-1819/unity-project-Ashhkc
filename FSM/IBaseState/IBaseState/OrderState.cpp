#include "OrderState.h"
#include "Waiter.h"
#include "KitchenState.h"

int OrderState::customerNumber = 0; // count how many customers are placing orders

OrderState::OrderState()
{
	
}

OrderState::~OrderState()
{
}

void OrderState::Enter(Waiter * wait)
{
	std::cout << "Hello, may I take your order?" << std::endl;
	Sleep(1000);
}

void OrderState::Execute(Waiter * wait)
{
	wait->ChangeState(new KitchenState());
}

void OrderState::Exit(Waiter * wait)
{
	customerNumber++;
	std::cout << "Is that everything?  Great, I'll just put that through for you!" << std::endl;
	std::cout << "Customer number: " << customerNumber << std::endl << std::endl;
	Sleep(1000);
}

