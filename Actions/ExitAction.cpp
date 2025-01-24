#include "ExitAction.h"

ExitAction::ExitAction(ApplicationManager* pAppManager):Action(pAppManager)
{
}


void ExitAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(p);
}

void ExitAction::Execute()
{
	pManager->GetClipboard();
}