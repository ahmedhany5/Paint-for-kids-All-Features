#include "AddCircleAction.h"
#include "../Figures/CCircle.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <iostream>
using namespace std;

AddCircleAction::AddCircleAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddCircleAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();	// pointers & getters to use pOut & pIn
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Circle: Click at first corner");
	pIn->GetPointClicked(P1.x, P1.y);
																// Read 2 corners & store them 
	pOut->PrintMessage("New Circle: Click at second corner");
	pIn->GetPointClicked(P2.x, P2.y);

	CircleGfxInfo.isFilled = false;	//default is not filled
	CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();	//get drawing, filling colors
	CircleGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();
}

bool AddCircleAction::Execute()		//Execute the action 
{
	ReadActionParameters();															//This action needs to read some parameters first
	CCircle* C = new CCircle(P1, P2, CircleGfxInfo);	//Create a cirlce with the parameters read from the user
	pManager->AddFigure(C);															//Add circle to the list of figures
	return true;
}