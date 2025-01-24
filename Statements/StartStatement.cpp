#include "StartStatement.h"
#include <iostream>
#include <sstream>
using namespace std;

StartStatement::StartStatement()
{
}

StartStatement::StartStatement(Point cp)
{
	xLocation = cp.x;
	yLocation = cp.y;
	centerpoint = cp;
	pOutconn = NULL;
	outlet.y = centerpoint.y + UI.ASSGN_HI;
	outlet.x = centerpoint.x + UI.ASSGN_WDTH / 2;

}

void StartStatement::Draw(Output* pOut) const
{
	pOut->DrawStartAndEnd(centerpoint, UI.ASSGN_WDTH, UI.ASSGN_HI, "start", Selected);
}
void StartStatement::Save(ofstream& OutFile)
{
	OutFile << "STRT  " << ID << "  " << centerpoint.x + (0.5) * UI.ASSGN_WDTH << "  " << centerpoint.y << endl;
}
void StartStatement::Load(ifstream& Infile)
{
	Infile >> ID >> centerpoint.x >> centerpoint.y;
}
void StartStatement::UpdateStatementText()
{
	ostringstream T;
	T << "Start";
	Text = T.str();
}