#pragma once
#include "Action.h"
#include "..\ApplicationManager.h"
#include <string>
#include <fstream>
class LoadAction:public Action
{
	private:
		ifstream File;
		string FileName;
	public:
		LoadAction(ApplicationManager* pAppManager);
		virtual void ReadActionParameters();
		virtual void Execute();

};

