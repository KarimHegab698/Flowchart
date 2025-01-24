#include "AddConditional.h"
#include "..\ApplicationManager.h"
AddConditional::AddConditional(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddConditional::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Conditional Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();


	pOut->PrintMessage("Conditional Statement: Enter the variable");
	LHS = pIn->GetVariable(pOut);

	pOut->PrintMessage("Conditional Statement: Enter the condition");
	cond = pIn->GetCompOperator(pOut);

	pOut->PrintMessage("Value Assignment Statement: Enter the Valriable or Value");
	RHS = pIn->GetString(pOut);

}

void AddConditional::Execute()
{
	ReadActionParameters();
	Point P;
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P);
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	ConditionalStatement* pAssign = new ConditionalStatement(Corner,P, "", "", "");
	pAssign->setLHS(LHS);
	pAssign->setRHS(RHS);
	pAssign->setOP(cond);



	pManager->AddStatement(pAssign);
}
