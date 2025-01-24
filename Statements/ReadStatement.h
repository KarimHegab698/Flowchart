#pragma once
#include "Statement.h"
class ReadStatement:public Statement
{
	string read;
	Connector* pOutConn;
	Point Inlet;
	Point Outlet;
	Point LeftCorner;
	virtual void UpdateStatementText();
public:
	ReadStatement();
	ReadStatement(Point Lcorner, Point P, string Read = "");
	void setRead(const string& R);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

