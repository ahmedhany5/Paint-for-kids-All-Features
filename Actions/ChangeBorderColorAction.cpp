#include "ChangeBorderColorAction.h"
#include "../ApplicationManager.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include <iostream>

ChangeBorderColorAction::ChangeBorderColorAction(ApplicationManager* pApp): Action(pApp)
{
	SelectedFig = NULL;
}
void ChangeBorderColorAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Please choose the border colour number: 1-Black. 2-Yellow. 3-Orange. 4-Red. 5-Green. 6-Blue. ");
	ColorChosenS = pIn->GetString(pOut);
	SelectedFig = pManager->GetSelected();
	if (ColorChosenS == "1")
		ColorChosen = BLACK;
	else if (ColorChosenS == "2")
		ColorChosen = YELLOW;
	else if (ColorChosenS == "3")
		ColorChosen = ORANGE;
	else if (ColorChosenS == "4")
		ColorChosen = RED;
	else if (ColorChosenS == "5")
		ColorChosen = GREEN;
	else if (ColorChosenS == "6")
		ColorChosen = BLUE;
	else
	{
		pOut->PrintMessage("Undefined color number!");
		ColorChosen = pOut->getCrntDrawColor();
	}
}

bool ChangeBorderColorAction::Execute()
{
	Input* pIn = pManager->GetInput();
	Output* P = pManager->GetOutput();
	ReadActionParameters();
	SelectedFig = pManager->GetSelected();  //get the selected figure
	if (SelectedFig == NULL)
	{
		P->PrintMessage("Select a figure first!");
		return false;
	}
	else
	{
		SelectedFig->ChngDrawClr(ColorChosen);
		SelectedFig->SetSelected(false);
		return true;
	}
}