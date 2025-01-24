#pragma once
#include "Action.h"
class SelectAndUnselect:public Action
{
		Point ClickedPoint;

	public:
		SelectAndUnselect(ApplicationManager* pAppManager);

		virtual void ReadActionParameters();
		virtual void Execute();
};

