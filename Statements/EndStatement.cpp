#include "EndStatement.h"
#include <iostream>
#include <sstream>
using namespace std;
EndStatement::EndStatement()
{}

EndStatement::EndStatement(Point cp)
{
	xLocation = cp.x;
	yLocation = cp.y;
	centerpoint = cp;
	pOutconn = NULL;
	inlet.x = centerpoint.x + UI.ASSGN_WDTH / 2;
	inlet.y = centerpoint.y;
}

void EndStatement::Draw(Output* pOut) const
{
	pOut->DrawStartAndEnd(centerpoint, UI.ASSGN_WDTH, UI.ASSGN_HI, "End", Selected);
}

void EndStatement::Save(ofstream& OutFile)
{
	OutFile << "END  " << ID << "  " << centerpoint.x + (0.5) * UI.ASSGN_WDTH << "  " << centerpoint.y << endl;
}
void EndStatement::Load(ifstream& Infile)
{
	Point P;
	Infile >> ID >> P.x >> P.y;
}
void EndStatement::UpdateStatementText()
{
	ostringstream T;
	T << "End";
	Text = T.str();
}