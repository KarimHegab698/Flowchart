#pragma once
#include "Statement.h"

class ConditionalStatement : public Statement
{
	string LHS;
	string RHS;
	string Op;
	Connector* pOutConn1;
	Connector* pOutConn2;
	Point Inlet;
	Point Outlet1;
	Point Outlet2;
	Point LeftCorner;
	virtual void UpdateStatementText();
public:
	ConditionalStatement();
	ConditionalStatement(Point Lcorner, Point P, string LeftHS = "", string op = "", string RightHS = "");
	void setLHS(const string& L);
	void setRHS(const string& R);
	void setOP(const string& O);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};
