
#include "Input.h"
#include "Output.h"
using namespace std;
#include <iostream>
Input::Input(window* pW)
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(Point& P) const
{
	pWind->WaitMouseClick(P.x, P.y);	//Wait for mouse click
}

string Input::GetString(Output* pO) const
{
	string Label;
	char Key;
	while (1)
	{
		pWind->WaitKeyPress(Key);
		if (Key == 27)	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		if (Key == 13)	//ENTER key is pressed
			return Label;
		if ((Key == 8) && (Label.size() >= 1))	//BackSpace is pressed
			Label.resize(Label.size() - 1);
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}


double Input::GetValue(Output* pO) const	// Reads a double value from the user 
{
	///TODO: add code to read a double value from the user and assign it to D

	double D = 0;

	//This function should make any needed validations on the entered text 
	// to make sure it is a double value (e.g. 12.5, -12.5, -23, -23., -23.0 …etc.).
	//string value = GetString(pO);
	//pO->PrintMessage("Please enter a value");
	//string value;
	while (true)
	{
		string value = GetString(pO);
		if (IsValue(value))
		{
			D = stod(value);
			break;
		}
	}
	//Read a double value from the user

	return D;
}

string Input::GetVariable(Output* pO) const
{
	//string variable=GetString(pO);
	//pO->PrintMessage("Please enter a variable:");
	while (true)
	{
		string variable = GetString(pO);
		if (IsVariable(variable))
		{
			return variable;
			break;
		}
	}
}
string Input::GetArithOperator(Output* pO) const
{
	//string ao=GetString(pO);
	while (true)
	{
		string ao = GetString(pO);
		//for (int i = 0; i < ao.size(); i++)
		//{
		if (ao.size() == 1)
		{
			if (ao[0] == 42 || ao[0] == 43 || ao[0] == 45 || ao[0] == 47)
			{
				return ao;
				break;
			}
		}
		else
		{
			pO->PrintMessage("Please Re-Enter");
		}
		//}
		/*else
		{
			//pO->PrintMessage("Invalid operator. Please enter a valid arithmetic operator.");
		}*/
	}
	//return ao;
}
string Input::GetCompOperator(Output* pO) const
{
	//string co = GetString(pO);

	while (true)
	{
		string co = GetString(pO);
		if (co.size() == 2||co.size()==1)
		{
			for (int i = 0; i < co.size(); i++)
			{
				if ((co[i] == 61 && co[i + 1] == 61) || (co[i] == 60 && co[i + 1] == 61) || (co[i] == 62 && co[i + 1] == 61) || (co[i] == 33 && co[i + 1] == 61) || (co[i] == 60) || (co[i] == 62))
				{
					return co;
					break;
					//if (co[i] == 61 || co[i] == 33 || co[i] == 60 || co[1] == 62)
					//{
						//if ((co[1] == 61 && co[2] == 61) || (co[1] == 33 && co[2] == 61) || (co[1] == 60 && co[2] == 61) || (co[1] == 62 && co[2] == 61))
						//{
							//return co;
							//break;
						//}
						/*else
						{
							pO->PrintMessage("Invalid operator. Please enter a valid comparison operator.");
						}*/
				}
			}
		}
		else
		{
			pO->PrintMessage("Please Re-Enter");
		}
	}
	//return co;
}

ActionType Input::GetUserAction() const
{
	//This function reads the position where the user clicks to determine the desired action

	int x, y;
	pWind->WaitMouseClick(x, y);	//Get the coordinates of the user click

	if (UI.AppMode == DESIGN)	//application is in design mode
	{
		//[1] If user clicks on the Toolbar
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_START:return ADD_START;
			case ITM_END:return ADD_END;
			case ITM_VALUE_ASSIGN: return ADD_VALUE_ASSIGN;
			case ITM_VAR_ASSIGN: return ADD_VAR_ASSIGN;
			case ITM_OPER_ASSIGN:return ADD_OPER_ASSIGN;
			case ITM_COND: return ADD_CONDITION;
			case ITM_READ:return ADD_READ;
			case ITM_WRITE:return ADD_WRITE;
			case ITM_CONNECTOR:return ADD_CONNECTOR;
			case ITM_SELECT:return SELECT;
			case ITM_EDIT:return EDIT_STAT;
			case ITM_DEL:return DEL;
			case ITM_COPY:return COPY;
			case ITM_CUT:return CUT;
			case ITM_PASTE:return PASTE;
			case ITM_SAVE:return SAVE;
			case ITM_LOAD:return LOAD;
			case ITM_EXIT: return EXIT;
			case ITM_SWITCH_SIM:return SWITCH_SIM_MODE;
			default: return DSN_TOOL;
			}
		}

		//[2] User clicks on the drawing area
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;
			else
				return OUTPUT_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}
	else	//Application is in Simulation mode
	{
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			//Check whick Menu item was clicked
			//This assumes that menu items are lined up horizontally
			int ClickedItem = (x / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on
			switch (ClickedItem)
			{
			case ITM_VALIDATE:return VALIDATE;
			case ITM_RUN: return RUN;
			case ITM_SWITCH_DSN:return SWITCH_DSN_MODE;
			case ITM_SIM_EXIT:return EXIT;
			default: return TOOL_SIM;
			}
		}
		// TODO: This should be changed after creating the compelete simulation bar 
		//return SWITCH_DSN_MODE;	// THIS SHOULD BE CHANGED
		if (y >= UI.ToolBarHeight && y < UI.height - UI.StatusBarHeight)
		{
			if (x <= UI.DrawingAreaWidth)
				return DRAWING_AREA;
			else
				return OUTPUT_AREA;
		}

		//[3] User clicks on the status bar
		return STATUS;
	}

}


Input::~Input()
{
}
