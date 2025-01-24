#pragma once
#include "Statement.h"
class VariableAssign:public Statement
{
private:
	string LHS;
	string RHS;

	Connector* pOutConn;
	Point Inlet;
	Point Outlet;
	Point LeftCorner;

	virtual void UpdateStatementText();

public:
	VariableAssign();
	VariableAssign(Point Lcorner, Point P, string LeftHS = "", string RightHS = "");

	void setLHS(const string& L);
	void setRHS(const string& R);

	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

