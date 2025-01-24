#include "AddConnector.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <sstream>

using namespace std;
AddConnector::AddConnector(ApplicationManager* pAppManager):Action(pAppManager)
{
	Startstat = NULL;
	Endstat = NULL;
}
void AddConnector::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	Point Start;
	Point End;
	pOut->PrintMessage("Connector Action:Choose a Start Statement");
	while (Startstat == NULL)
	{
		pIn->GetPointClicked(Start);
		Startstat = pManager->GetStatement(Start);
	}
	pOut->PrintMessage("Connector Action:Choose a End Statement");
	while (Endstat == NULL)
	{
		pIn->GetPointClicked(End);
		Endstat = pManager->GetStatement(End);
	}
	
}
void AddConnector::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	Point P;
	if (pManager->GetStatCount() == 1)
	{
		pOut->PrintMessage("Can't add a connector");
		pIn->GetPointClicked(P);
		pOut->ClearStatusBar();
		return;
	}
	ReadActionParameters();
	Connector* Pconn = new Connector(Startstat, Endstat);
	pManager->AddConnector(Pconn);
	Pconn->Draw(pOut);
}