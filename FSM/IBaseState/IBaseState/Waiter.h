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

	bool isCustomer;

public:
	Waiter();
	~Waiter();

	void Update();
	void ChangeState(IBaseState* newState);

	bool isCustomerPresent = false;
	bool isFoodCooked = false;
	bool isTableFinished = false;


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

