#pragma once
#include "IBaseState.h"

class IdleState :
	public IBaseState

{
private:
	
public:
	IdleState();
	~IdleState();

	void Enter(Waiter* wait);
	void Execute(Waiter* wait);
	void Exit(Waiter* wait);
};

