#pragma once
#include "Action.h"
class AddVariable :public Action
{
	Point Position;
	string LHS;
	string RHS;
public:
	AddVariable(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};

