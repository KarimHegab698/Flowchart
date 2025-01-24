#pragma once
#include "Action.h"
#include "..\Statements\Statement.h"
#include "..\ApplicationManager.h"
class PasteAction : public Action
{
private:
	Point P;
	Statement* pasted;
public:
	PasteAction(ApplicationManager* pAppManager);

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();


};