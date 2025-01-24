#pragma once
#include "Statement.h"
class StartStatement:public Statement
{
	Connector* pOutconn;
	Point outlet;
	Point centerpoint;
	virtual void UpdateStatementText();
public:
	StartStatement();
	StartStatement(Point cp);
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& Infile);
};

