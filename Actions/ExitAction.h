#pragma once
#include "Action.h"
#include "..\Statements\Statement.h"
#include "..\ApplicationManager.h"
class ExitAction : public Action
{
private:
	Point p;
	Statement* Exit;


public:
	ExitAction(ApplicationManager* pAppManager);
	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};