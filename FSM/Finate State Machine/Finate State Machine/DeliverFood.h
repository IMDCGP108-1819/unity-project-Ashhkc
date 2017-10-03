#pragma once
#include "IState.h"

class DeliverFood : public IState
{
public:
	DeliverFood();
	~DeliverFood();
	int Override UpdateState();
	int Override PrintStateInfo();

private:
	bool foodDelivered = false;
	bool foodCollected = false;
};

