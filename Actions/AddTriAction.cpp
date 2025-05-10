#include "AddTriAction.h"
#include "../Figures/CTriangle.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <iostream>
using namespace std;

AddTriAction::AddTriAction(ApplicationManager* pApp) :Action(pApp)
{}
void AddTriAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput(); // pointers pIn & pOut and getters for Output & Input 
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Triangle: Click at first corner");
	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("New Triangle: Click at second corner");					// read 3 corners and store them 
	pIn->GetPointClicked(P2.x, P2.y);

	pOut->PrintMessage("New Triangle: Click at third corner");
	pIn->GetPointClicked(P3.x, P3.y);

	TriGfxInfo.isFilled = false;	//default is not filled
	TriGfxInfo.DrawClr = pOut->getCrntDrawColor();	//get drawing, filling colors
	TriGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();
}

bool AddTriAction::Execute()	//Execute
{
	ReadActionParameters();		//This action needs to read some parameters first
	CTriangle* T = new CTriangle(P1, P2, P3, TriGfxInfo);	//Create a triangle with the parameters read from the user
	pManager->AddFigure(T);		//Add triangle to the list of figures
	return true;
}