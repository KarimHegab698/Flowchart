#include "Output.h"


Output::Output()
{
	//Initialize user interface parameters
	UI.width = 1500;
	UI.height = 800;
	UI.wx = 15;
	UI.wy = 15;

	UI.AppMode = DESIGN;	//Design Mode is the default mode

	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 55;
	UI.MenuItemWidth = 65;
	UI.DrawingAreaWidth = 0.75 * UI.width;

	UI.DrawColor = BLUE;
	UI.HighlightColor = RED;
	UI.MsgColor = RED;

	UI.ASSGN_WDTH = 150;
	UI.ASSGN_HI = 50;

	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Programming Techniques Project");

	pWind->SetPen(RED, 3);
	CreateDesignToolBar();
	CreateStatusBar();
	ClearDrawArea();
	ClearOutputBar();
}


Input* Output::CreateInput()
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int wd, int h, int x, int y)
{
	return new window(wd, h, x, y);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar()
{
	pWind->DrawLine(0, UI.height - UI.StatusBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateDesignToolBar() //Draws the Design Menu
{
	UI.AppMode = DESIGN;	//Design Mode

	//fill the tool bar 

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way

	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in Defs.h ==> enum DrawMenuItem
	string MenuItemImages[DSN_ITM_CNT];
	MenuItemImages[ITM_VALUE_ASSIGN] = "images\\Assign.jpg";
	MenuItemImages[ITM_COND] = "images\\Condition.jpg";
	MenuItemImages[ITM_EXIT] = "images\\Exit.jpg";
	MenuItemImages[ITM_START] = "images\\Start.jpg";
	MenuItemImages[ITM_END] = "images\\End.jpg";
	MenuItemImages[ITM_READ] = "images\\Read.jpg";
	MenuItemImages[ITM_WRITE] = "images\\Write.jpg";
	MenuItemImages[ITM_VAR_ASSIGN] = "images\\VarAssign.jpg";
	MenuItemImages[ITM_OPER_ASSIGN] = "images\\OpAssign.jpg";
	MenuItemImages[ITM_CONNECTOR] = "images\\Connector.jpg";
	MenuItemImages[ITM_SELECT] = "images\\Select.jpg";
	MenuItemImages[ITM_EDIT] = "images\\Edit.jpg";
	MenuItemImages[ITM_DEL] = "images\\Delete.jpg";
	MenuItemImages[ITM_COPY] = "images\\Copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\Cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\Paste.jpg";
	MenuItemImages[ITM_SAVE] = "images\\Save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\Load.jpg";
	MenuItemImages[ITM_SWITCH_SIM] = "images\\SwitchSim.jpg";
	//TODO: Prepare images for each menu item and add it to the list


	//Draw menu item one image at a time
	//for (int i = 0; i < 22; i++) pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	ClearToolBar();
	for (int i = 0; i < DSN_ITM_CNT; i++)
		pWind->DrawImage(MenuItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
//TODO: Complete this function
void Output::CreateSimulationToolBar() //Draws the Simulation Menu
{
	UI.AppMode = SIMULATION;	//Simulation Mode
	///TODO: add code to create the simulation tool bar
	string SimItemImages[SIM_ITM_CNT];
	SimItemImages[ITM_VALIDATE] = "images\\Validate.jpg";
	SimItemImages[ITM_RUN] = "images\\Run.jpg";
	SimItemImages[ITM_SWITCH_DSN] = "images\\Design.jpg";
	SimItemImages[ITM_SIM_EXIT] = "images\\SimExit.jpg";
	ClearToolBar();
	for (int i = 0; i < SIM_ITM_CNT; i++)
		pWind->DrawImage(SimItemImages[i], i * UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	pWind->SetPen(RED, 2);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar()
{
	pWind->SetPen(WHITE, 0);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);
}
/////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearDrawArea()
{
	pWind->SetPen(RED, 2);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.DrawingAreaWidth, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearOutputBar()
{
	//Create output bar by drawing a filled rectangle
	pWind->SetPen(RED, 2);
	pWind->SetBrush(LIGHTBLUE);
	pWind->DrawRectangle(UI.DrawingAreaWidth, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::PrintMessage(string msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD, BY_NAME, "Arial");
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight / 1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::DrawString(const int iX, const int iY, const string Text)
{
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(iX, iY, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Statements Drawing Functions							//
//======================================================================================//

//Draw assignment statement and write the "Text" on it
void Output::DrawAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}

//TODO: Add similar functions for drawing all other statements.
void Output::DrawConditionStat(Point Left, int width, int height, string Text, bool Selected)
{
	const int ipx[4] = { Left.x,Left.x + width / 2,Left.x + width,Left.x + width / 2 };
	const int ipy[4] = { Left.y,Left.y + height / 2,Left.y,Left.y - height / 2 };
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	pWind->DrawPolygon(ipx, ipy, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + 67, Left.y - 10, Text);
}
void Output::DrawReadAndWrite(Point Left, int width, int height, string Text, bool Selected)
{
	const int ipx[4] = { Left.x,Left.x + width ,Left.x + width / 2,Left.x - width / 2 };
	const int ipy[4] = { Left.y,Left.y,Left.y + height,Left.y + height };
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color


	pWind->DrawPolygon(ipx, ipy, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + 25, Left.y + 18, Text);
}
/*void Output::DrawWrite(Point Left, int width, int height, string Text, bool Selected)
{
	const int ipx[4] = { Left.x,Left.x + width / 3,Left.x + width,Left.x + width / 3 };
	const  int ipy[4] = { Left.y,Left.y + height / 3,Left.y,Left.y - height / 3 };
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	pWind->DrawPolygon(ipx, ipy, 4);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}*/
void Output::DrawStartAndEnd(Point center, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color 

	pWind->DrawEllipse(center.x - width, center.y - height, center.x + width, center.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(center.x - 10, center.y - 5, Text);
}
/*void Output::DrawEnd(Point center, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color 

	pWind->DrawEllipse(center.x - width, center.x + width, center.y - height, center.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(center.x + width / 4, center.y + height / 4, Text);
}*/
void Output::DrawVarAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}
void Output::DrawOpAssign(Point Left, int width, int height, string Text, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color

	//Draw the statement block rectangle
	pWind->DrawRectangle(Left.x, Left.y, Left.x + width, Left.y + height);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}

//		e.g. DrawCondtionalStat(......), DrawStart(......), DrawEnd(.......), ...etc
//		Decide the parameters that should be passed to each of them

//TODO: Add DrawConnector function
void Output::DrawConnector(Point Left, Point Right, bool Selected)
{
	if (Selected)	//if stat is selected, it should be highlighted
		pWind->SetPen(UI.HighlightColor, 3);	//use highlighting color
	else
		pWind->SetPen(UI.DrawColor, 3);	//use normal color 

	//pWind->DrawLine(Left.x,Left.y,Left.x+width/2,Left.y);
	pWind->DrawLine(Left.x, Left.y, Right.x, Right.y );
	//pWind->DrawTriangle(Left.x+width/2,Left.y-width/10,Left.x+width/2,Left.y+width/10,Left.x+1.2*(width/2),Left.y);
	pWind->DrawTriangle(Left.x + 10, Left.y + 20, Left.x - 10, Left.y + 20, Left.x, Left.y + 1.2 * 20);

	//Write statement text
	pWind->SetPen(BLACK, 2);
	//pWind->DrawString(Left.x + width / 4, Left.y + height / 4, Text);
}
//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

