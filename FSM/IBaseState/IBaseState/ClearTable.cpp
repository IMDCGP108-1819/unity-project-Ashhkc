#include "ClearTable.h"
#include "IdleState.h"
#include "Waiter.h"

ClearTable::ClearTable()
{
}


ClearTable::~ClearTable()
{
}

void ClearTable::Enter(Waiter * wait)
{
	Sleep(1000);
	std::cout << "Goodbye, see you soon!" << std::endl;
}

void ClearTable::Execute(Waiter * wait)
{
	wait->ChangeState(new IdleState());
}

void ClearTable::Exit(Waiter * wait)
{
	tableClearedReference++;
	std::cout << "Cleared table up after customer: " << tableClearedReference << std::endl << std::endl;
	wait->isTableFinished = false;
	// TEST
	//*wStates = WaitStates::DELIVER_FOOD; 
}
