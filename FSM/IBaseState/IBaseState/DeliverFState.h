#pragma once
#include "IBaseState.h"

class DeliverFState :
	public IBaseState

{
private:
	static int foodDelivered;


public:
	DeliverFState();
	~DeliverFState();

	void Enter(Waiter* wait);
	void Execute(Waiter* wait);
	void Exit(Waiter* wait);
};

