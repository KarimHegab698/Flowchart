#pragma once
#include "Action.h"
#include <fstream>
#include <string>
class SaveAction:public Action
{
private:
	ofstream File;
	string FileName;
public:
	SaveAction(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};

