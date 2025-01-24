#pragma once
#include "Action.h"
class AddRead :public Action
{
	Point Position;
	string LHS;
	string RHS;
public:
	AddRead(ApplicationManager* pAppManager);


	virtual void ReadActionParameters();

	virtual void Execute();
};

