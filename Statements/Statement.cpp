#include "Statement.h"

int Statement::ID = 0;

Statement::Statement()	
{ 
	//TODO: set the ID with a unique value
	ID=ID+1;
	Text = "";
	Selected = false;		
}

void Statement::SetSelected(bool s)
{	Selected = s; }

bool Statement::IsSelected() const
{	return Selected; }

void Statement::SetStatementPoint(Point P)
{
	xLocation = P.x;
	yLocation = P.y;
}

Point Statement::GetStatementPoint()
{
	return Point(xLocation, yLocation);
}