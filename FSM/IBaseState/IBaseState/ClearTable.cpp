#include "ClearTable.h"
#include "IdleState.h"
#include "Waiter.h"

int ClearTable::tableCount = 0; // count which customer has finished their food and left

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
	tableCount++;
	std::cout << "Cleared table up after customer: " << tableCount << std::endl << std::endl;
	wait->isTableFinished = false;
}
