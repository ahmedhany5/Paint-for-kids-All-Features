#pragma once
#include <iostream>
using namespace std;
#ifndef CTRI_H
#define CTRI_H
#include "CFigure.h"
class CTriangle : public CFigure //class CTriangle inherites from class CFigure
{
private:
	Point Corner1; Point Corner2; Point Corner3;	// 3 points for the triangle 
	Point centre;

public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo);		// 3 points, the id, and its figure
	virtual void Draw(Output* pOut) const;
	double area(int x1, int y1, int x2, int y2, int x3, int y3);
	virtual bool isInside(int x, int y);								//check if the coordinates (x,y) lie inside the figure
	virtual void Save(ofstream& OutFile);								//save figure parameters in the file 
	void Load(ifstream&);								//load figure parameters in the file
	virtual void PrintInfo(Output* pOut);	
	Point getTrianglePoint1() const;                                 //get other points of triangle
	Point getTrianglePoint2() const;
	Point getTrianglePoint3() const;
	Point getTriangleCentre() const;

};
#endif