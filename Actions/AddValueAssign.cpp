#include "AddValueAssign.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

#include <sstream>
#include <iostream>
using namespace std;

//constructor: set the ApplicationManager pointer inside this action
AddValueAssign::AddValueAssign(ApplicationManager *pAppManager):Action(pAppManager)
{}

void AddValueAssign::ReadActionParameters()
{
	Input *pIn = pManager->GetInput();
	Output *pOut = pManager->GetOutput();
	
	//Read the (Position) parameter
	pOut->PrintMessage("Value Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();		

	//TODO: Ask the user in the status bar to enter the LHS and set the data member
	pOut->PrintMessage("Please Enter The Left Hand Side:");
	while (true)
	{
		LHS = pIn->GetString(pOut);
		if (IsVariable(LHS))
		{
			//pManager->GetStatement(Position);
			//cout << LHS;
			break;
		}
		else
		{
			pOut->PrintMessage("Please Re-Enter");
		}
	}
	//TODO: Ask the user in the status bar to enter the RHS and set the data member
	pOut->PrintMessage("Please Enter The Right Hand Side:");
	while (true)
	{
		RHS = pIn->GetValue(pOut);
		//cout << RHS;
		break;
		if (IsValue(to_string(RHS)))
		{
			//cout << RHS;
			//pManager->GetStatement(Position);
			break;
		}
		else
		{
			//pOut->PrintMessage("Please Re-Enter");
		}
	}

	//Note: You should validate the LHS to be variable name and RHS to be a value
	//      Call the appropriate functions for this.
}

void AddValueAssign::Execute()
{
	ReadActionParameters();
		
	
	//Calculating left corner of assignement statement block
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH/2;
	Corner.y = Position.y ;
	
	ValueAssign *pAssign = new ValueAssign(Corner, "", 0);
	//TODO: should set the LHS and RHS of pAssign statement
	pAssign->setLHS(LHS);
	pAssign->setRHS(RHS);
	//      with the data members set and validated before in ReadActionParameters()

	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}