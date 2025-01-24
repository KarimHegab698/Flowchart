#include "ReadStatement.h"
#include <sstream>

using namespace std;

ReadStatement::ReadStatement()
{}

ReadStatement::ReadStatement(Point Lcorner, Point P, string Read)
{
	xLocation = P.x;
	yLocation = P.y;
	LeftCorner = Lcorner;
	read = Read;
	UpdateStatementText();
	pOutConn = NULL;
	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void ReadStatement::setRead(const string& R)
{
	read = R;
	UpdateStatementText();
}

void ReadStatement::Draw(Output* pOut) const
{
	pOut->DrawReadAndWrite(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void ReadStatement::Save(ofstream& OutFile)
{
	OutFile << "READ" << "  " << ID << "  " << LeftCorner.x << "  " << LeftCorner.y << "  " << read << endl;
}

void ReadStatement::Load(ifstream& Infile)
{
	Infile >> ID >> LeftCorner.x >> LeftCorner.y >> read;
	UpdateStatementText();
}
void ReadStatement::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << "Read " << read;
	Text = T.str();
}