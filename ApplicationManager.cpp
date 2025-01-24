#include "ApplicationManager.h"
#include "Actions\AddValueAssign.h"
#include "GUI\Input.h"
#include "GUI\Output.h"
#include "Actions/AddConnector.h"
#include "Actions/AddRectAction.h"
#include "Actions/SelectAndUnselect.h"
#include "Actions/CopyAction.h"
#include "Actions/LoadAction.h"
#include "Actions/PasteAction.h"
#include "Actions/SaveAction.h"
#include "Actions/AddConditional.h"
#include "Actions/AddEnd.h"
#include "Actions/AddOperator.h"
#include "Actions/AddRead.h"
#include "Actions/AddStart.h"
#include "Actions/AddVariable.h"
#include "Actions/AddWrite.h"
#include "Actions/ExitAction.h"
#include "Actions/SwitchToSim.h"
#include "Actions/SwitchToDis.h"
//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	StatCount = 0;
	ConnCount = 0;
	pSelectedStat = NULL;	//no Statement is selected yet
	pClipboard = NULL;
	
	//Create an array of Statement pointers and set them to NULL		
	for(int i=0; i<MaxCount; i++)
	{
		StatList[i] = NULL;	
		ConnList[i] = NULL;
	}
}


//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//


ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to ActioType, create the corresponding action object
	switch (ActType)
	{
		case ADD_VALUE_ASSIGN:
			pAct = new AddValueAssign(this);
			break;

		case ADD_CONDITION:
			pAct = new AddConditional(this);///create AddCondition Action here
			break;

		case SELECT:
			///create Select Action here
			pAct = new SelectAndUnselect(this);
			break;

		case EXIT:
			///create Exit Action here
			break;
		
		case SAVE:
			pAct = new SaveAction(this);
			break;

		case COPY:
			pAct = new CopyAction(this);
			break;

		case PASTE:
			pAct = new PasteAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case ADD_READ:
			pAct = new AddRead(this);
			break;

		case ADD_WRITE:
			pAct = new AddWrite(this);
			break;

		case ADD_START:
			pAct = new AddStart(this);
			break;

		case ADD_VAR_ASSIGN:
			pAct = new AddVariable(this);
			break;

		case ADD_CONNECTOR:
		//	pAct = new AddConnector(this);
			break;

		case ADD_OPER_ASSIGN:
			pAct = new AddOperator(this);
			break;

		case ADD_END:
			pAct = new AddEnd(this);
			break;

		case SWITCH_SIM_MODE:
			pAct = new SwitchToSim(this);
			break;

		case SWITCH_DSN_MODE:
			pAct = new SwitchToDis(this);
			break;

		case STATUS:
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
	}
}



//==================================================================================//
//						Statements Management Functions								//
//==================================================================================//


//Add a statement to the list of statements
void ApplicationManager::AddStatement(Statement *pStat)
{
	if(StatCount < MaxCount)
		StatList[StatCount++] = pStat;
	
}

void ApplicationManager::AddConnector(Connector* pConn)
{
	for (int i = 0; i < ConnCount; i++)
	{
		ConnList[i] = pConn;
	}
}
Connector *ApplicationManager::GetConnector(Point P) const
{
	if (ConnList[0] == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < ConnCount; i++)
	{
		if (ConnList[i])
		{
			return ConnList[i];
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////
Statement *ApplicationManager::GetStatement(Point P) const
{
	//If this point P(x,y) belongs to a statement return a pointer to it.
	//otherwise, return NULL
	if (StatList[0] == NULL)
	{
		return NULL;
	}
	for (int i = 0; i < StatCount; i++)
	{
		if (StatList[i])
		{
			return StatList[i];
		}
	}

	///Add your code here to search for a statement given a point P(x,y)	
	///WITHOUT breaking class responsibilities

	return NULL;
}
////////////////////////////////////////////////////////////////////////////////////
//Returns the selected statement
Statement *ApplicationManager::GetSelectedStatement() const
{	return pSelectedStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Set the statement selected by the user
void ApplicationManager::SetSelectedStatement(Statement *pStat)
{	pSelectedStat = pStat;	}

////////////////////////////////////////////////////////////////////////////////////
//Returns the Count
int ApplicationManager::GetStatCount()
{	return StatCount;	}
int ApplicationManager::GetConnCount()
{
	return ConnCount;
}


////////////////////////////////////////////////////////////////////////////////////
//Returns the Clipboard
Statement* ApplicationManager::GetClipboard() const
{
	return pClipboard;
}

////////////////////////////////////////////////////////////////////////////////////
//Set the Clipboard
void ApplicationManager::SetClipboard(Statement *pStat)
{	pClipboard = pStat;	}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//


//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{
	pOut->ClearDrawArea();

	//Draw all statements
	for(int i=0; i<StatCount; i++)
		StatList[i]->Draw(pOut);
	
	//Draw all connections
	for(int i=0; i<ConnCount; i++)
		ConnList[i]->Draw(pOut);

}
////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////

void ApplicationManager::SaveAll(ofstream& OutFile)
{
	StatCount = GetStatCount();
	OutFile << StatCount << endl;
	for (int i = 0; i < StatCount; i++)
	{
		StatList[i]->Save(OutFile);
		OutFile << endl;
	}
}
void ApplicationManager::LoadAll(ifstream& Infile)
{
	Statement* pStat;
	string StatType;
	Infile >> StatCount;
	for (int i = 0; i < StatCount; i++)
	{
		Infile >> StatType;
		if (StatType == "STRT")
		{
			StatList[i] = new StartStatement();
			StatList[i]->Load(Infile);
		}
		else if (StatType == "READ")
		{
			StatList[i] = new ReadStatement();
			StatList[i]->Load(Infile);
		}
		else if (StatType == "COND")
		{
			StatList[i] = new ConditionalStatement();
			StatList[i]->Load(Infile);
		}
		else if (StatType == "OP_ASSIGN")
		{
			StatList[i] = new OperatorAssign();
			StatList[i]->Load(Infile);
		}
		else if (StatType=="WRITE")
		{
			StatList[i] = new WriteStatement();
			StatList[i]->Load(Infile);
		}
		else if (StatType=="END")
		{
			StatList[i] = new EndStatement();
			StatList[i]->Load(Infile);
		}
		else if (StatType == "VAR_ASSIGN")
		{
			StatList[i] = new VariableAssign();
			StatList[i]->Load(Infile);
		}
		else if (StatType == "VALUE_ASSIGN")
		{
			StatList[i] = new ValueAssign();
			StatList[i]->Load(Infile);
		}
		//StatList[i]->Load(Infile);
	}
}


//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<StatCount; i++)
		delete StatList[i];
	for(int i=0; i<StatCount; i++)
		delete ConnList[i];
	delete pIn;
	delete pOut;
	
}
