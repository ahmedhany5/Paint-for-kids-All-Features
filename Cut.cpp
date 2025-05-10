#include "Actions/Copy.h"
#include "Cut.h"
#include "Actions/Delete.h"
#include "ApplicationManager.h"
#include "Actions/Action.h"
#include <sstream>
using namespace std;


Cut::Cut(ApplicationManager* pAppManager) : Action(pAppManager)
{

}

void Cut::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

	pOut->PrintMessage("Please Select a Figure to cut");

	pOut->ClearStatusBar();
}

bool Copy::Execute()
{

	ReadActionParameters();
	CFigure* getfigure = pManager->GetSelected();  //get the selected one
	Input* pIn = pManager->GetInput();
	Output* P = pManager->GetOutput();


	if (getfigure)
	{
		pManager->SetClipboard(getfigure); //put the figure in the clipboard
		Delete SetSelected(false);  //delete it from the window
		P->PrintMessage("Statement CUT SUCCESSFULLY!");
		return true;
	}
	else
	{
		P->PrintMessage("NO STATEMENT WAS SELECTED");
		return false;
	}

	//////////////////////////////////////////////////////////////////////////////////







}
