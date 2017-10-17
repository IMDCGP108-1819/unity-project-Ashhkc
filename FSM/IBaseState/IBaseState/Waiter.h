#pragma once

#include "IBaseState.h"

//enum restaurantPosition { hungryTable, emptyTable, waitingTable, kitchen, waiting };

//enum WaitStates { IDLE, TAKE_ORDER, TELL_KITCHEN, DELIVER_FOOD, CLEAR_TABLE };

//WaitStates* wStates;


class Waiter
{
private: 
	//restaurantPosition pos;
	IBaseState* currentState;

	bool isCustomer;

public:
	Waiter();
	~Waiter();

	void Update();
	void ChangeState(IBaseState* newState);
	void AddToList();

	bool isCustomerPresent = false;
	bool isFoodCooked = false;
	bool isTableFinished = false;	
};

