#pragma once
#include "Statement.h"
class OperatorAssign : public Statement
{
	string LHS;
	string RHS;
	string Arth;

	Connector* pOutConn;

	Point Inlet;
	Point Outlet;

	Point LeftCorner;
	virtual void UpdateStatementText();
public:
	OperatorAssign();
	OperatorAssign(Point Lcorner, Point P, string LeftHS = "", char A = ' ', string RightHS = "");

	void setLHS(const string& L);
	void setRHS(const string& R);
	void setArth(const string a);


	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

