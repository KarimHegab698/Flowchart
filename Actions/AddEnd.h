#pragma once
#include "Action.h"
class AddEnd :public Action
{
	Point Position;
public:
	AddEnd(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};