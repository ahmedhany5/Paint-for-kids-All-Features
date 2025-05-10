#include "CSquare.h"
#include<iostream>
using namespace std;
CSquare::CSquare(Point P1, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	length = 100;
	//ID = 200 + LastID; // square's 1 point and its id and length for isInside
	TypeName = "Square";
}

void CSquare::Draw(Output* pOut) const
{
	pOut->DrawSQ(Corner1, FigGfxInfo, Selected);	//Call DrawSQ to draw in the screen	
}

bool CSquare::isInside(int x, int y)
{
	if (x >= (Corner1.x-(length/2)) && x <= (Corner1.x + (length/2)) && y >= (Corner1.y-(length/2)) && y <= (Corner1.y + (length/2)))
		return true;
	else
		return false;
}

void CSquare::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Square, the ID is: " + to_string(ID) + ",  Center : (" + to_string(Corner1.x) +","+ to_string(Corner1.y) + ") ,Color: " + FigGfxInfo.FillClr.ReturnColor());	// message to be shown in the bar
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << TypeName << '\t' << ID << '\t' << Corner1.x << '\t' << Corner1.y << '\t' << FigGfxInfo.DrawClr.ReturnColor() << '\t';
	if (FigGfxInfo.isFilled == true)
	{
		OutFile << FigGfxInfo.FillClr.ReturnColor() << endl;
	}
	else {
		OutFile << "NO_FILL" << endl;
	}
}
void CSquare::Load(ifstream& FileInputStream)
{
	FigGfxInfo.BorderWdth = 3;
	if (FileInputStream.is_open())
	{
		FileInputStream >> ID >> Corner1.x >> Corner1.y >> FigGfxInfo.DrawClr >> FigGfxInfo.FillClr;
		if (FileInputStream.peek() != '\n')FileInputStream >> length;
		if (FileInputStream.peek() != '\n')FileInputStream >> FigGfxInfo.BorderWdth;
		if (FigGfxInfo.FillClr == TRANSPARENT_COLOR)
			FigGfxInfo.isFilled = false;
		return;
	}
}