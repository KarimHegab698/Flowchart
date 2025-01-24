#include "AddVariable.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"
AddVariable::AddVariable(ApplicationManager* pAppManager) : Action(pAppManager)
{}

void AddVariable::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("Variable Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();


	pOut->PrintMessage("Variable Assignment Statement: Enter the variable");
	LHS = pIn->GetVariable(pOut);


	pOut->PrintMessage("Variable Assignment Statement: Enter the Variable");
	RHS = pIn->GetVariable(pOut);


}

void AddVariable::Execute()
{
	ReadActionParameters();


	Point Corner;
	Point P;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	VariableAssign* pAssign = new VariableAssign(Corner, P, LHS, RHS);
	pAssign->setLHS(LHS);
	pAssign->setRHS(RHS);



	pManager->AddStatement(pAssign);
}
