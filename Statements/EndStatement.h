#pragma once
#include "Statement.h"
class EndStatement:public Statement
{
		Connector * pOutconn;
		Point inlet;
		Point centerpoint;
		virtual void UpdateStatementText();

	public:
		EndStatement();
		EndStatement(Point cp);
		virtual void Draw(Output* pOut) const;
		virtual void Save(ofstream& OutFile);
		virtual void Load(ifstream& Infile);
};

