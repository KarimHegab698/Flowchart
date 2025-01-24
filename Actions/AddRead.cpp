#include "AddRead.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"

AddRead::AddRead(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddRead::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Read Statement: Click to add the statement");

	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();



	pOut->PrintMessage("Read  Statement: Enter the Variable");
	RHS = pIn->GetVariable(pOut);
}

void AddRead::Execute()
{
	ReadActionParameters();


	Point P;
	Point Corner;
	Corner.x = Position.x - UI.ASSGN_WDTH / 2;
	Corner.y = Position.y;

	ReadStatement* pAssign = new ReadStatement(Corner,P, "");
	//TODO: should set the LHS and RHS of pAssign statement
	//      with the data members set and validated before in ReadActionParameters()
	pAssign->setRead(RHS);



	pManager->AddStatement(pAssign); // Adds the created statement to application manger's statement list
}
