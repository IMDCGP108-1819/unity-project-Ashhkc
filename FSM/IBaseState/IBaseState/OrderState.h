#pragma once
#include "IBaseState.h"

class OrderState :
	public IBaseState

{
private:
	static int customerNumber;

public:
	OrderState();
	~OrderState();

	void Enter(Waiter* wait);
	void Execute(Waiter* wait);
	void Exit(Waiter* wait);


};

