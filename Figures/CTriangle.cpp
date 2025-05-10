#include "CTriangle.h"
#include <iostream>
using namespace std;

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1; Corner2 = P2; Corner3 = P3;
						// 3 points for the triangle 
	TypeName = "Triangle";
	centre.x = (P1.x + P2.x + P3.x) / 3;
	centre.y = (P1.y + P2.y + P3.y) / 3;
}

void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTRI(Corner1, Corner2, Corner3, FigGfxInfo, Selected);		//call DrawTRI to draw on the screen 
}

double CTriangle::area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	return abs((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0);		// area of triangle 
}

bool CTriangle::isInside(int x, int y)
{
	double A = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);		// check if the shape is inside
	double A1 = area(x, y, Corner2.x, Corner2.y, Corner3.x, Corner3.y);
	double A2 = area(Corner1.x, Corner1.y, x, y, Corner3.x, Corner3.y);
	double A3 = area(Corner1.x, Corner1.y, Corner2.x, Corner2.y, x, y);
	if (A == (A1 + A2 + A3))
		return true;
	else
		return false;
}

void CTriangle::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Triangle the ID is: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
		+ "), Corner 2: (" + to_string(Corner2.x) + to_string(Corner2.y) + "), Corner 3: (" + to_string(Corner3.x) + "," + to_string(Corner3.y) + "), " + "Color: " + FigGfxInfo.FillClr.ReturnColor());
}
Point CTriangle::getTriangleCentre() const
{
	return centre;
}
Point CTriangle::getTrianglePoint1() const
{
	return Corner1;
}
Point CTriangle::getTrianglePoint2() const
{
	return Corner2;
}
Point CTriangle::getTrianglePoint3() const
{
	return Corner3;
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << TypeName << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t' << Corner3.x << '\t' << Corner3.y << '\t' << FigGfxInfo.DrawClr.ReturnColor() << '\t';
	if (FigGfxInfo.isFilled == true)
	{
		OutFile << FigGfxInfo.FillClr.ReturnColor() << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
void CTriangle::Load(ifstream& FileInputStream)
{
	FigGfxInfo.BorderWdth = 3;
	if (FileInputStream.is_open())
	{
		FileInputStream >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> Corner3.x >> Corner3.y >> FigGfxInfo.DrawClr >> FigGfxInfo.FillClr;
		if (FileInputStream.peek() != '\n')FileInputStream >> FigGfxInfo.BorderWdth;
		if (FigGfxInfo.FillClr == TRANSPARENT_COLOR)
			FigGfxInfo.isFilled = false;
		return;
	}
}