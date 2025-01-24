#include "CopyAction.h"

CopyAction::CopyAction(ApplicationManager* pAppManager):Action(pAppManager)
{}


void CopyAction::ReadActionParameters()
{


	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select the shape you want to copy");
	pIn->GetPointClicked(P);

}

void CopyAction::Execute()
{
	Statement* Copied = pManager->GetSelectedStatement();
	if (Copied != NULL)
	{
		Statement* CP = pManager->GetClipboard();
		if (CP != NULL)
		{
			delete CP;
		}
		pManager->SetClipboard(Copied);
	}
	//pManager->SetClipboard(Copied); 
	//pManager->SetSelectedStatement(Copied);

}