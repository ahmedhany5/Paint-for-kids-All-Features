#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	Point Center;
public:
	CRectangle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(int x, int y);
	virtual void Save(ofstream& OutFile);	//Save the figure parameters to the file

	virtual void Load(ifstream& InFile);	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
	Point getCenter();
	Point getPoint1();
	Point getPoint2();
};

#endif