#pragma once
#include "IBaseState.h"

class DeliverFState :
	public IBaseState

{
private:
	int foodDelivered = 0;
	int& foodReference = foodDelivered;


public:
	DeliverFState();
	~DeliverFState();

	void Enter(Waiter* wait);
	void Execute(Waiter* wait);
	void Exit(Waiter* wait);
};

