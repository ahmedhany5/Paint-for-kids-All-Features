#include "AddSQAction.h"
#include "../Figures/CSquare.h"
#include "../ApplicationManager.h"
#include "../GUI/Input.h"
#include "../GUI/Output.h"
#include <iostream>
using namespace std;

AddSQAction::AddSQAction(ApplicationManager* pApp) :Action(pApp)
{}

void AddSQAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();	// pointers pIn & pOut and getters for Output & Input 
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Sqaure: Click at a center");
	pIn->GetPointClicked(P1.x, P1.y);					//square reads 1 point only and store it

	SQGfxInfo.isFilled = false;	//default is not filled
	SQGfxInfo.DrawClr = pOut->getCrntDrawColor();	//get drawing, filling colors
	SQGfxInfo.FillClr = pOut->getCrntFillColor();
	pOut->ClearStatusBar();
}

bool AddSQAction::Execute() //Execute
{
	ReadActionParameters();		//This action needs to read some parameters first
	CSquare* S = new CSquare(P1, SQGfxInfo);		//Create a square with the parameters read from the user
	pManager->AddFigure(S);		//Add square to the list of figures
	return true;
}