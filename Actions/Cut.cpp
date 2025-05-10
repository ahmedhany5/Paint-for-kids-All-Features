#include "../Actions/Copy.h"
#include "Cut.h"
#include "../Actions/Delete.h"
#include "../ApplicationManager.h"
#include "../Actions/Action.h"
#include <iostream>
using namespace std;


Cut::Cut(ApplicationManager* pAppManager) : Action(pAppManager)
{

}

void Cut::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Please Select a Figure to cut");
}

bool Cut::Execute()
{

	ReadActionParameters();
	Input* pIn = pManager->GetInput();
	Output* P = pManager->GetOutput();
	CFigure* selected_figure = pManager->GetSelected();

	if (selected_figure==NULL)
	{
		P->PrintMessage("NO FIGURE WAS SELECTED");
		return false;
	}
	else
	{
		color Old = (selected_figure->getColor());
		pManager->SetClipboard(selected_figure); //put the figure in the clipboard
		selected_figure->ChngFillClr(GREY);
		P->PrintMessage("FIGURE CUT SUCCESSFULLY!");
		return true;
	}

	//////////////////////////////////////////////////////////////////////////////////







}
