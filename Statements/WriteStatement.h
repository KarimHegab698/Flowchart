#pragma once
#include "Statement.h"
class WriteStatement:public Statement
{
	string write;
	Connector* pOutConn;
	Point Inlet;
	Point Outlet;
	Point LeftCorner;
	virtual void UpdateStatementText();
public:
	WriteStatement();
	WriteStatement(Point Lcorner, Point p, string Write = "");
	void setwrite(const string& W);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
	
};

