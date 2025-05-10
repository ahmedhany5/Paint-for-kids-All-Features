#include "CCircle.h"
#include <iostream>
using namespace std;

CCircle::CCircle(Point P1, Point P2,GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1; Corner2 = P2;		// circle's 2 points and its id 
    TypeName = "Circle";
	radius = sqrt(pow(P1.y - P2.y, 2) + pow(P1.x - P2.x, 2));
}

void CCircle::Draw(Output* pOut) const
{
	pOut->DrawCIRCLE(Corner1, Corner2, FigGfxInfo, Selected);	//Call DrawCIRCLE to draw on screen
}

bool CCircle::isInside(int x, int y) 
{
	Point Center = Corner1;
	double result = pow((x - Center.x), 2) + pow((y - Center.y), 2);
	double radius_squared = pow(radius, 2);
	if (result > radius_squared)
		return false;
	else
		return true;
}

void CCircle::PrintInfo(Output* pOut)
{
    pOut->PrintMessage("Circle: ID: " + to_string(ID) + ", Center: (" + to_string(Corner1.x) + "," + to_string(Corner1.y) + "), Color: " + FigGfxInfo.FillClr.ReturnColor());	// message to be shown in the bar
}

double CCircle::getCircleRadius()
{
	return radius;

}
void CCircle::Load(ifstream& Infile)
{
}
void CCircle::Save(ofstream& OutFile)
{
	OutFile << TypeName << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << Corner2.x << '\t' << Corner2.y << '\t' << FigGfxInfo.DrawClr.ReturnColor() << '\t';
	if (FigGfxInfo.isFilled == true)
	{
		OutFile << FigGfxInfo.FillClr.ReturnColor() << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}	
}
