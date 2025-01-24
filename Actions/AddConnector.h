#pragma once
#include "Action.h"
#include "..\Connector.h"
class AddConnector:public Action
{
private:
	Statement* Startstat;
	Statement* Endstat;
public:
	AddConnector(ApplicationManager* pAppManager);
	virtual void ReadActionParameters();
	virtual void Execute();
};

