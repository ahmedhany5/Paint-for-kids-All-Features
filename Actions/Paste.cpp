
#include "Paste.h"
#include "../ApplicationManager.h"
#include "../Actions/Action.h"
#include "../Figures/CFigure.h"
#include "../Figures/CRectangle.h"
#include "../Figures/CSquare.h"
#include "../Figures/CHexagon.h"
#include "../Figures/CCircle.h"
#include "../Figures/CTriangle.h"
#include <iostream>
#include "../Actions/Cut.h"
using namespace std;

Paste::Paste(ApplicationManager* pAppManager) :Action(pAppManager)
{
}

void Paste::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Click to PASTE the figure copied");
	pIn->GetPointClicked(p.x, p.y);  //to get where to paste
	pOut->ClearStatusBar();
}

bool Paste::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CFigure* getfigure = pManager->GetClipboard(); //make getclipboard in application manager
	if (getfigure->getColor() == GREY)
	{
		pManager->DeleteFigureTemporary(getfigure->getID());
		pManager->ClearDrawingArea();
	}

	if (getfigure == NULL)
	{
		pOut->PrintMessage("Nothing to PASTE");
		return false;
	}
	else if (getfigure->getTypeName() == "Rectangle")
	{
		getfigure->SetSelected(false);
		GfxInfo SQGfxInfo;
		SQGfxInfo.isFilled = getfigure->isFilled();	//get isFilled or not
		SQGfxInfo.DrawClr = getfigure->getBorderColor();	//get border color
		SQGfxInfo.FillClr = getfigure->getColor();  //get filled color
		pOut->ClearStatusBar();
		Point distance; //distance between point clicked and original center
		distance.x = p.x - (((CRectangle*)getfigure)->getCenter()).x;
		distance.y = p.y - (((CRectangle*)getfigure)->getCenter()).y;
		Point P1, P2;
		P1.x = (((CRectangle*)getfigure)->getPoint1()).x + distance.x;
		P1.y = (((CRectangle*)getfigure)->getPoint1()).y + distance.y;
		P2.x = (((CRectangle*)getfigure)->getPoint2()).x + distance.x;
		P2.y = (((CRectangle*)getfigure)->getPoint2()).y + distance.y;
		CRectangle* S = new CRectangle(P1,P2, SQGfxInfo);		//Create a square with the parameters read from the user
		pManager->AddFigure(S);		//Add square to the list of figures
	}
	else if (getfigure->getTypeName() == "Square")
	{
		getfigure->SetSelected(false);
		GfxInfo SQGfxInfo;
		SQGfxInfo.isFilled = getfigure->isFilled();	//get isFilled or not
		SQGfxInfo.DrawClr = getfigure->getBorderColor();	//get border color
		SQGfxInfo.FillClr = getfigure->getColor();  //get filled color
		pOut->ClearStatusBar();
		CSquare* S = new CSquare(p, SQGfxInfo);		//Create a square with the parameters read from the user
		pManager->AddFigure(S);		//Add square to the list of figures
	}
	else if (getfigure->getTypeName() == "Hexagon")
	{
		getfigure->SetSelected(false);
		GfxInfo SQGfxInfo;
		SQGfxInfo.isFilled = getfigure->isFilled();	//get isFilled or not
		SQGfxInfo.DrawClr = getfigure->getBorderColor();	//get border color
		SQGfxInfo.FillClr = getfigure->getColor();  //get filled color
		pOut->ClearStatusBar();
		CHexagon* S = new CHexagon(p, SQGfxInfo);		//Create a square with the parameters read from the user
		pManager->AddFigure(S);		//Add square to the list of figures
	}
	else if (getfigure->getTypeName() == "Circle")
	{
		getfigure->SetSelected(false);
		GfxInfo SQGfxInfo;
		SQGfxInfo.isFilled = getfigure->isFilled();	//get isFilled or not
		SQGfxInfo.DrawClr = getfigure->getBorderColor();	//get border color
		SQGfxInfo.FillClr = getfigure->getColor();  //get filled color
		pOut->ClearStatusBar();
		double radius = ((CCircle*)getfigure)->getCircleRadius();
		Point Radius;
		Radius.x = p.x + radius * cos(3.14 / 2);
		Radius.y = p.y + radius * sin(3.14 / 2);
		CCircle* S = new CCircle(p,Radius, SQGfxInfo);		//Create a square with the parameters read from the user
		pManager->AddFigure(S);		//Add square to the list of figures
	}
	else if (getfigure->getTypeName() == "Triangle")
	{
		getfigure->SetSelected(false);
		GfxInfo SQGfxInfo;
		SQGfxInfo.isFilled = getfigure->isFilled();	//get isFilled or not
		SQGfxInfo.DrawClr = getfigure->getBorderColor();	//get border color
		SQGfxInfo.FillClr = getfigure->getColor();  //get filled color
		pOut->ClearStatusBar();
		Point distance;
		distance.x = p.x - (((CTriangle*)getfigure)->getTriangleCentre()).x;
		distance.y = p.y - (((CTriangle*)getfigure)->getTriangleCentre()).y;
		Point p1;
		Point p2;
		Point p3;
		p1.x = (((CTriangle*)getfigure)->getTrianglePoint1()).x + distance.x;
		p1.y = (((CTriangle*)getfigure)->getTrianglePoint1()).y + distance.y;
		p2.x = (((CTriangle*)getfigure)->getTrianglePoint2()).x + distance.x;
		p2.y = (((CTriangle*)getfigure)->getTrianglePoint2()).y + distance.y;
		p3.x = (((CTriangle*)getfigure)->getTrianglePoint3()).x + distance.x;
		p3.y = (((CTriangle*)getfigure)->getTrianglePoint3()).y + distance.y;
		CTriangle* S = new CTriangle(p1,p2,p3, SQGfxInfo);		//Create a square with the parameters read from the user
		pManager->AddFigure(S);		//Add square to the list of figures
	}
	return true;
}







