#pragma once
#include "IBaseState.h"

class OrderState :
	public IBaseState

{
public:
	OrderState();
	~OrderState();

	void Enter(Waiter* wait);
	void Execute(Waiter* wait);
	void Exit(Waiter* wait);


};

