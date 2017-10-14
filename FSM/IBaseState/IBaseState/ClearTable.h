#pragma once
#include "IBaseState.h"

class ClearTable :
	public IBaseState
{
private:
	int tableCount = 0;
	int& tableClearedReference = tableCount;

public:
	ClearTable();
	~ClearTable();


	void Enter(Waiter* wait);
	void Execute(Waiter* wait);
	void Exit(Waiter* wait);
};

