#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

class Waiter;

class IBaseState
{
private:

public:
	virtual ~IBaseState() {};


	   ////////////////////////////////////////////////////////////////////
	  // Functions to be included in every class, this makes sure that  // 
	 // they are performing the correct actions at the right time     //
	//////////////////////////////////////////////////////////////////

	virtual void Enter(Waiter*) = 0;
	virtual void Execute(Waiter*) = 0;
	virtual void Exit(Waiter*) = 0;
};

