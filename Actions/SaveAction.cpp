#include "SaveAction.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

SaveAction::SaveAction(ApplicationManager* pAppManager):Action(pAppManager)
{}

void SaveAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please Enter File Name");
	FileName = pIn->GetString(pOut);
	FileName += ".txt";
}

void SaveAction::Execute()
{
	ReadActionParameters();
	File.open(FileName, ios::out);
	if (File.is_open())
	{
		pManager->SaveAll(File);
		File.close();
	}
}