#include "AddWrite.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"


AddWrite::AddWrite(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddWrite::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Read Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
	pOut->PrintMessage("Read Statement: Enter the variable or message");
	RHS = pIn->GetString(pOut);
}

void AddWrite::Execute()
{
	ReadActionParameters();


	Point P;
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	WriteStatement* pAssign = new WriteStatement(Corner,P, "");
	pAssign->setwrite(RHS);



	pManager->AddStatement(pAssign);
}
