#pragma once
#include"Action.h"
#include "..\Statements\Statement.h"
#include "..\ApplicationManager.h"

class CopyAction :public Action
{
private:
	Point P;
	Statement* copied;
public:

	CopyAction(ApplicationManager* pAppManager);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};