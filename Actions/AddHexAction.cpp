#include "AddHexAction.h"
#include "../Figures/CHexagon.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <iostream>
using namespace std;

AddHexAction::AddHexAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddHexAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();	// pointers pIn & pOut and getters
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Hexagon: Click one corner");	// read 1 corner only and store it
	pIn->GetPointClicked(P1.x, P1.y);

	HexGfxInfo.isFilled = false;	//default is not filled
	HexGfxInfo.DrawClr = pOut->getCrntDrawColor();	//get drawing, filling colors
	HexGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();
}

bool AddHexAction::Execute()	//Execute
{
	ReadActionParameters();		//This action needs to read some parameters first
	CHexagon* H = new CHexagon(P1, HexGfxInfo);		//Create a hexagon with the parameters read from the user
	pManager->AddFigure(H);		//Add hexagon to the list of figures
	return true;
}