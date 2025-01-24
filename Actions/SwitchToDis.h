#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
class SwitchToDis :public Action
{
public:

	SwitchToDis(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};

