#pragma once
#include "IBaseState.h"

class KitchenState :
	public IBaseState

{
public:
	KitchenState();
	~KitchenState();

	void Enter(Waiter* wait);
	void Execute(Waiter* wait);
	void Exit(Waiter* wait);

	bool canYouSeeMe = false;
};

