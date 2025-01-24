#include "SelectAndUnselect.h"
#include "..\ApplicationManager.h"

#include "..\GUI/Input.h"
#include "..\GUI/Output.h"

#include <sstream>

SelectAndUnselect::SelectAndUnselect(ApplicationManager* pAppManager) : Action(pAppManager) {}

void SelectAndUnselect::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Click on a statement or connector to select or unselect it");
	pIn->GetPointClicked(ClickedPoint);
	pOut->ClearStatusBar();
}

void SelectAndUnselect::Execute()
{
	ReadActionParameters();

	Statement* pStatement = pManager->GetStatement(ClickedPoint);


	if (pStatement)  // If the clicked point contains a statement
	{
		if (pManager->GetSelectedStatement() != pStatement)   // If the clicked statement is not the current selected statement
		{
			pManager->GetSelectedStatement()->SetSelected(false); // unselect the currently selected statement
			pManager->SetSelectedStatement(pStatement); // Select the clicked statement
		}
		else // The clicked statement is the currently selected statement
		{
			pManager->SetSelectedStatement(nullptr);
		}
	}



	pManager->UpdateInterface();
}

