// IBaseState.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

class Waiter;

class IBaseState
{
private:

public:
	virtual ~IBaseState() {};

	//Used to change state
	virtual void Update() = 0;

	//Enter, execute and exit functions
	virtual void Enter(Waiter*) = 0;
	virtual void Execute(Waiter*) = 0;
	virtual void Exit(Waiter*) = 0;
};

