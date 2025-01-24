#pragma once
#include "Action.h"
class AddWrite :public Action
{
	Point Position;
	string RHS;
public:
	AddWrite(ApplicationManager* pAppManager);

	virtual void ReadActionParameters();

	virtual void Execute();
};

