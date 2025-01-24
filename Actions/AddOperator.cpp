#include "AddOperator.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"

AddOperator::AddOperator(ApplicationManager* pAppManager) : Action(pAppManager)
{}

void AddOperator::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	pOut->PrintMessage("Operator Assignment Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();


	pOut->PrintMessage("operator Assignment Statement: Enter the variable");
	LHS = pIn->GetVariable(pOut);

	pOut->PrintMessage("operator Assignment Statement: Enter the arthematic operation");
	Arth = pIn->GetArithOperator(pOut);

	pOut->PrintMessage("Operator Assignment Statement: Enter the Variable Or a Value");
	RHS = pIn->GetString(pOut);


}

void AddOperator::Execute()
{
	ReadActionParameters();


	Point P;
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	OperatorAssign* pAssign = new OperatorAssign(Corner,P, "", 0);

	pAssign->setLHS(LHS);
	pAssign->setRHS(RHS);
	pAssign->setArth(Arth);


	pManager->AddStatement(pAssign);
}
