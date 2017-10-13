#pragma once
// IBaseState.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>
using namespace std::this_thread;
using namespace std::chrono_literals;

class Waiter;

class IBaseState
{
private:

public:
	virtual ~IBaseState() {};

	//Enter, execute and exit functions
	virtual void Enter(Waiter*) = 0;
	virtual void Execute(Waiter*) = 0;
	virtual void Exit(Waiter*) = 0;
};

