#pragma once

#include "IBaseState.h"
#include "RestaurantPosition.h"

class IBaseState;

class Waiter :
	public IBaseState

{
private: 
	IBaseState* currentState;
	restaurantPosition pos;

	// take order
	bool readyToOrder;
	bool orderTaken;

	// tell kitchen
	bool processingOrder;
	bool orderProcessed;

	// deliver food
	int tableNumber;
	bool foodReady;
	bool foodDelivered;

	// clear table

public:
	Waiter();
	~Waiter();
};

