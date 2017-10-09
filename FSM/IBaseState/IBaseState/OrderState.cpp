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
	std::cout << "Hi, may I take your order?" << std::endl;
	//sleep_for(3s);
}

void OrderState::Execute(Waiter * wait)
{
	wait->ChangeState(new KitchenState());

}

void OrderState::Exit(Waiter * wait)
{
	std::cout << "I'll just get that for you... (->TellKitchenState)" << std::endl;
}

