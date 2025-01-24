#include "PasteAction.h"


PasteAction::PasteAction(ApplicationManager* pAppManager):Action(pAppManager)
{}

void PasteAction::ReadActionParameters()
{


	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Select the area you want to paste in ");
	pIn->GetPointClicked(P);

}

void PasteAction::Execute()
{
	ReadActionParameters();
	if (pManager->GetClipboard() == NULL)
	{
		Output* Pout = pManager->GetOutput();
		Pout->PrintMessage("no statment to be pasted ");

	}
	else {

		//Statement* CP = (pManager->GetClipboard())->CP();  ///This needs clone function in each statement class to get the right statement type
		//CP->SetPoint(P); ///made pure virtual function called SetPoint to locate the position in Statement.h and should be implemented in all statements classes
		//pManager->AddStatement(CP);

	}

}