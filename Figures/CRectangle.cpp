#include "CRectangle.h"
#include "../CMUgraphicsLib/colors.h"
#include <iostream>
using namespace std;

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
    TypeName = "Rectangle";
	Center.x = (P1.x + P2.x) / 2;
	Center.y = (P1.y + P2.y) / 2;
}
	

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

//DONE (Ahmed): returns true if the coordinates (x,y) lie inside the rectangle
bool CRectangle::isInside(int x, int y)
{
    // Ensure that Corner1 is the top-left corner and Corner2 is the bottom-right corner
    int LeftX = min(Corner1.x, Corner2.x);
    int TopY = min(Corner1.y, Corner2.y);
    int RightX = max(Corner1.x, Corner2.x);
    int BottomY = max(Corner1.y, Corner2.y);

    // Check if (x, y) lies inside the rectangle
    if (x >= LeftX && x <= RightX && y >= TopY && y <= BottomY)
        return true;

    return false;
}

void CRectangle::Save(ofstream& OutFile)
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

void CRectangle::PrintInfo(Output* pOut)
{
    string msg = "Rectangle, ID: " + to_string(ID) + ", Corner 1: (" + to_string(Corner1.x) + "," + to_string(Corner1.y)
        + "), Corner 2: (" + to_string(Corner2.x) + "," + to_string(Corner2.y) + "), " + "Color: " + FigGfxInfo.FillClr.ReturnColor();
    pOut->PrintMessage(msg);

}

Point CRectangle::getCenter()
{
	return Center;
}

Point CRectangle::getPoint1()
{
	return Corner1;
}

Point CRectangle::getPoint2()
{
	return Corner2;
}
void CRectangle::Load(ifstream& FileInputStream)
{
	FigGfxInfo.BorderWdth = 3;
	if (FileInputStream.is_open())
	{
		FileInputStream >> ID >> Corner1.x >> Corner1.y >> Corner2.x >> Corner2.y >> FigGfxInfo.DrawClr >> FigGfxInfo.FillClr;
		if (FileInputStream.peek() != '\n')FileInputStream >> FigGfxInfo.BorderWdth;
		if (FigGfxInfo.FillClr == TRANSPARENT_COLOR)
			FigGfxInfo.isFilled = false;
		return;
	}
}
