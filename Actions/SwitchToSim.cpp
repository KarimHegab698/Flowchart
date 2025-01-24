#include "SwitchToSim.h"


SwitchToSim::SwitchToSim(ApplicationManager* pAppManager):Action(pAppManager)
{
}

void SwitchToSim::ReadActionParameters()
{
}

void SwitchToSim::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	if (UI.AppMode == DESIGN)
	{
		pOut->CreateSimulationToolBar();
	}
	else
	{
		pOut->CreateDesignToolBar();
	}
}