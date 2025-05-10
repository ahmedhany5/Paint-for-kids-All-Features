#include "Copy.h"
#include <iostream>
using namespace std;

Copy::Copy(ApplicationManager* pAppManager) :Action(pAppManager)
{

}

void Copy::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Please Select a figure to COPY");
	
	pOut->ClearStatusBar();
}

bool Copy::Execute()
{

	ReadActionParameters();
	CFigure* selected_figure = pManager->GetSelected();  //get the selected one
	Input* pIn = pManager->GetInput();
	Output* P = pManager->GetOutput();

	

	if (selected_figure)
	{
		pManager->SetClipboard(selected_figure);
		P->PrintMessage("Figure COPIED SUCCESSFULLY!");
		return true;
	}
	else
	{
		P->PrintMessage("NO Figure WAS SELECTED");
		return false;
	}



}


