#pragma once
#include "Action.h"
class AddStart :public Action
{
	Point Position;
public:
	AddStart(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};

