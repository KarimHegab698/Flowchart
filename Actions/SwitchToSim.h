#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
class SwitchToSim: public Action
{

	public:
		SwitchToSim(ApplicationManager* pAppManager);

		//Reads parameters required for action to execute
		virtual void ReadActionParameters();

		//Execute action (code depends on action type)
		virtual void Execute();
};

