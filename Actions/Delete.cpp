#include "Delete.h"
#include <iostream>
using namespace std;


Delete::Delete(ApplicationManager* pAppManager) :Action(pAppManager)
{
}


void Delete::ReadActionParameters()
{
	CFigure* getfigure = pManager->GetSelected();  //get the selected one
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();

}

bool Delete::Execute()
{
	CFigure* getfigure = pManager->GetSelected();  //get the selected one
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();


	if (pManager->GetSelected() == NULL)
	{
		pOut->PrintMessage("NO FIGURE WAS SELECTED");;
	}

	else {
		pManager->DeleteFigure(getfigure->getID());	//select/unselect the figure
		pManager->ClearDrawingArea();
		pOut->PrintMessage("Figure Deleted");


	}
	return true;
}