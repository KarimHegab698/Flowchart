#include "ConditionalStatement.h"
#include <sstream>

using namespace std;

ConditionalStatement::ConditionalStatement()
{
}

ConditionalStatement::ConditionalStatement(Point Lcorner, Point P, string LeftHS, string op, string RightHS)
{
	LeftCorner.x = P.x;
	LeftCorner.y = P.y;
	LHS = LeftHS;
	RHS = RightHS;
	Op = op;
	UpdateStatementText();

	pOutConn1 = NULL;
	pOutConn2 = NULL;
	Inlet.x = LeftCorner.x + UI.ASSGN_WDTH / 2;
	Inlet.y = LeftCorner.y;
	Outlet1.x = LeftCorner.x;
	Outlet1.y = LeftCorner.y;
	Outlet2.x = LeftCorner.x + UI.ASSGN_WDTH;
	Outlet2.y = Outlet1.y;

}

void ConditionalStatement::setLHS(const string& L)
{
	LHS = L;
	UpdateStatementText();

}

void ConditionalStatement::setRHS(const string& R)
{
	RHS = R;
	UpdateStatementText();

}

void ConditionalStatement::setOP(const string& O)
{
	Op = O;
	UpdateStatementText();

}

void ConditionalStatement::Draw(Output* pOut) const
{
	pOut->DrawConditionStat(LeftCorner, UI.ASSGN_WDTH, UI.ASSGN_HI, Text, Selected);
}
void ConditionalStatement::Save(ofstream& OutFile)
{
	OutFile << "COND" <<" " << ID << "  " << LeftCorner.x + (0.5) * UI.ASSGN_WDTH << "  " << LeftCorner.y + (0.5) * UI.ASSGN_HI << "  " << LHS << "  " << Op << "  " << RHS << endl;
}
void ConditionalStatement::Load(ifstream& Infile)
{
	Infile >> ID >> LeftCorner.x >> LeftCorner.y >> LHS >> Op >> RHS;
}
void ConditionalStatement::UpdateStatementText()
{
	//Build the statement text: Left handside then equals then right handside
	ostringstream T;
	T << LHS << Op << RHS;
	Text = T.str();
}
