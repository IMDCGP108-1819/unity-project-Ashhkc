#pragma once

#include "IBaseState.h"

enum restaurantPosition
{
	hungryTable, emptyTable, waitingTable, kitchen, waiting
};

class Waiter
{
private: 

	restaurantPosition pos;
	IBaseState* currentState;

	bool isCustomerPresent;
	//bool isFoodCooked;

public:
	Waiter();
	~Waiter();

	bool isFoodCooked = false;

	void Update();
	void ChangeState(IBaseState* newState);

	const bool IsCustomerPresent() { return isCustomerPresent; }
	//const bool IsFoodCooked() { return isFoodCooked; }


	// take order
	/*bool readyToOrder;
	bool orderTaken;

	// tell kitchen
	bool processingOrder;
	bool orderProcessed;

	// deliver food
	int tableNumber;
	bool foodReady;
	bool foodDelivered;*/

	// clear table
	
};

