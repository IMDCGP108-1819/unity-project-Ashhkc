#include "OrderState.h"
#include "Waiter.h"
#include "KitchenState.h"
#include <windows.h>

OrderState::OrderState()
{
	
}

OrderState::~OrderState()
{
}

void OrderState::Enter(Waiter * wait)
{
	std::cout << "A new customer! (->TakeOrderState)" << std::endl;
	Sleep(1000);
}

void OrderState::Execute(Waiter * wait)
{
	std::cout << "Hi, may I take your order?" << std::endl;
	wait->ChangeState(new KitchenState());

}

void OrderState::Exit(Waiter * wait)
{
	std::cout << "I'll just get that for you... (->TellKitchenState)" << std::endl;
}

