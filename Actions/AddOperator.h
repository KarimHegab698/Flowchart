#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
class AddOperator : public Action
{
	Point Position;	//Position where the user clicks to add the stat.
	//TODO: you should add LHS and RHS of the assignment statement as parameters
	string LHS;
	string RHS;
	string Arth;

public:
	AddOperator(ApplicationManager* pAppManager);

	//Read Assignemt statements position
	virtual void ReadActionParameters();

	//Create and add an assignemnt statement to the list of statements
	virtual void Execute();
};