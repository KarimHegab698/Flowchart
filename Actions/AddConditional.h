#pragma once
#include "Action.h"
class AddConditional :public Action
{
	Point Position;
	string LHS;
	string RHS;
	string cond;
public:
	AddConditional(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();


	virtual void Execute();
};

