#include "SwitchToDis.h"

SwitchToDis::SwitchToDis(ApplicationManager* pAppManager) :Action(pAppManager)
{
}
void SwitchToDis::ReadActionParameters()
{
}
void SwitchToDis::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if (UI.AppMode == SIMULATION)
	{
		pOut->CreateDesignToolBar();
	}
	else
	{
		pOut->CreateSimulationToolBar();
	}
}