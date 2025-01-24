#include "LoadAction.h"
#include <iostream>
using namespace std;

LoadAction::LoadAction(ApplicationManager* pAppManager) :Action(pAppManager)
{}

void LoadAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please Enter File Nmae :");
	FileName = pIn->GetString(pOut);
	FileName += ".txt";
}

void LoadAction::Execute()
{
		ReadActionParameters();
		File.open(FileName, ios::in);
		if (File.is_open())
		{
			pManager->LoadAll(File);
			File.close();
		}
}