#include "WriteStatement.h"
#include <sstream>

using namespace std;

WriteStatement::WriteStatement()
{}

WriteStatement::WriteStatement(Point Lcorner, Point p, string Write)
{
	xLocation = p.x;
	yLocation = p.y;
	LeftCorner = Lcorner;
	write = Write;
	UpdateStatementText();
	pOutConn = NULL;
	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void WriteStatement::setwrite(const string& W)
{
	write = W;
	UpdateStatementText();
}

void WriteStatement::Draw(Output* pOut) const
{
	pOut->DrawReadAndWrite(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void WriteStatement::Save(ofstream& OutFile)
{
	OutFile << "WRITE  " << ID << "  " << LeftCorner.x << "  " << LeftCorner.y << "  " << write << endl;
}
void WriteStatement::Load(ifstream& Infile)
{
	Infile >> ID >> LeftCorner.x >> LeftCorner.y >> write;
	UpdateStatementText();
}
void WriteStatement::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << "Write " << write;
	Text = T.str();
}