#include "AddStart.h"
#include "..\ApplicationManager.h"
#include "..\GUI/Input.h"
#include "..\GUI/Output.h"
#include <sstream>
using namespace std;

AddStart::AddStart(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void AddStart::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("start Statement: Click to add the statement");
	pIn->GetPointClicked(Position);
	pOut->ClearStatusBar();

}

void AddStart::Execute()
{
	ReadActionParameters();
	Point Corner;
	Corner.x = Position.x;
	Corner.y = Position.y;
	StartStatement* pAssign = new StartStatement(Corner);
	pManager->AddStatement(pAssign);
}
