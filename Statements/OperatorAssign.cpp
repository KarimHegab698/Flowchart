#include "OperatorAssign.h"
#include <sstream>
#include"..\GUI\Input.h"
using namespace std;

OperatorAssign::OperatorAssign()
{
}

OperatorAssign::OperatorAssign(Point Lcorner, Point P, string LeftHS, char A, string RightHS)
{
	xLocation = P.x;
	yLocation = P.y;
	LHS = LeftHS;
	RHS = RightHS;
	Arth = A;
	UpdateStatementText();
	LeftCorner = Lcorner;

	pOutConn = NULL;

	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;

	Outlet.x = Inlet.x;
	Outlet.y = LeftCorner.y + UI.ASSGN_HI;
}

void OperatorAssign::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();
}

void OperatorAssign::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();
}

void OperatorAssign::setArth(const string a)
{
	Arth = a;
	UpdateStatementText();
}
void OperatorAssign::Draw(Output* pOut) const
{
	pOut->DrawOpAssign(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void OperatorAssign::Save(ofstream& OutFile)
{
	OutFile << "OP_ASSIGN  " << ID << "  " << LeftCorner.x << "  " << LeftCorner.y << "  " << LHS << "  " << Outlet.x << "  " << Arth << "  " << Outlet.y << endl;
}
void OperatorAssign::Load(ifstream& Infile)
{
	string Operator;
	Infile >> ID >> LeftCorner.x >> LeftCorner.y >> LHS >> Outlet.x >> Arth >> Outlet.y;
	UpdateStatementText();
}
void OperatorAssign::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << " = " << Outlet.x << " " << Arth << " " << Outlet.y;
	Text = T.str();
}