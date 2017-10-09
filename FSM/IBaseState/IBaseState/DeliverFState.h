#pragma once
#include "IBaseState.h"

class DeliverFState :
	public IBaseState

{
public:
	DeliverFState();
	~DeliverFState();

	void Enter(Waiter* wait);
	void Execute(Waiter* wait);
	void Exit(Waiter* wait);
};

