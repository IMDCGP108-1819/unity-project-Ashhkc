#pragma once

class IState
{
public:
	virtual void UpdateState () = 0;
	virtual void PrintStateInfo() = 0;

};