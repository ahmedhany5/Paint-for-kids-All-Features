#include "CHexagon.h"
#include<iostream>
using namespace std;
CHexagon::CHexagon(Point P1, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	Corner1 = P1;	// hexagon's 1 point and its id
    TypeName = "Hexagon";
}
void CHexagon::Draw(Output* pOut) const
{
	pOut->DrawHEX(Corner1, FigGfxInfo, Selected);	//Call DrawHEX to draw on screen 
}

bool CHexagon::isInside(int x, int y)
{
	//const int w = 150/sqrt(3);
	//int vertices_x[6] = { Corner1.x - w , Corner1.x - (w / 2),Corner1.x + (w / 2),Corner1.x + w,Corner1.x + (w / 2),Corner1.x - (w / 2) };
	//int vertices_y[6] = { Corner1.y ,Corner1.y - (w * sqrt(3) / 2), Corner1.y - (w * sqrt(3) / 2) , Corner1.y,Corner1.y + (w * sqrt(3) / 2),Corner1.y + (w * sqrt(3) / 2) };

	//// Check if the point lies inside the hexagon
	//bool inside = false;
	//for (int i = 0, j = 5; i < 6; j = i++) {
	//	if (((vertices_y[i] > y) != (vertices_y[j] > y)) &&
	//		(x < (vertices_x[j] - vertices_x[i]) * (y - vertices_y[i]) / (vertices_y[j] - vertices_y[i]) + vertices_y[i])) {
	//		return inside= true;
	//	}
	//}
	/*return inside;*/
	double deltaX = abs(x - Corner1.x);
	double deltaY = abs(y - Corner1.y);
	int size = 100/sqrt(3);

	// Check if the point is within the bounding rectangle of the hexagon
	if (deltaX <= size * sqrt(3) / 2 && deltaY <= size) {
		// Check if the point is above the bottom edge
		if (deltaY <= size / 2)
			return true;

		// Check if the point is inside the left or right triangle
		double slope = (size / 2) / (size * sqrt(3) / 2);
		if (deltaY <= size - slope * deltaX)
			return true;
	}

	return false;
}

void CHexagon::PrintInfo(Output* pOut)
{
    pOut->PrintMessage("Hexagon, the ID is: " + to_string(ID)+ ", Center: (" + to_string(Corner1.x) + ", " + to_string(Corner1.y) + "), Color : " + FigGfxInfo.FillClr.ReturnColor());		// message to be shown in the bar
}

void CHexagon::Save(ofstream& OutFile)
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
void CHexagon::Load(ifstream& FileInputStream)
{
	FigGfxInfo.BorderWdth = 3;
	if (FileInputStream.is_open())
	{
		FileInputStream >> ID >> Corner1.x >> Corner1.y >> FigGfxInfo.DrawClr >> FigGfxInfo.FillClr;
		if (FileInputStream.peek() != '\n')FileInputStream >> FigGfxInfo.BorderWdth;
		if (FigGfxInfo.FillClr == TRANSPARENT_COLOR)
			FigGfxInfo.isFilled = false;
		return;
	}
}