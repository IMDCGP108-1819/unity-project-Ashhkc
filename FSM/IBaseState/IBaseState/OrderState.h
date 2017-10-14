#pragma once
#include "IBaseState.h"

class OrderState :
	public IBaseState

{
private:
	int customerNumber = 0;
	int& customerReference = customerNumber;

public:
	OrderState();
	~OrderState();

	void Enter(Waiter* wait);
	void Execute(Waiter* wait);
	void Exit(Waiter* wait);


};

