#include "AddEnd.h"
#include "..\ApplicationManager.h"
using namespace std;
AddEnd::AddEnd(ApplicationManager* pAppManager) :Action(pAppManager)
{}



void AddEnd::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("End Statement: Click to add the statement");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();
}

void AddEnd::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x;
	Corner.y = Position.y;
	EndStatement* pAssign = new EndStatement(Corner);
	pManager->AddStatement(pAssign);

}
