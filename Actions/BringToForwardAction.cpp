#include "BringToForwardAction.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include <iostream>
using namespace std;

BringToForwardAction::BringToForwardAction(ApplicationManager* pApp) : Action(pApp)
{}

void BringToForwardAction::ReadActionParameters()
{}

bool BringToForwardAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* Selected = pManager->GetSelected();
	if (Selected != NULL)
	{
		pManager->BringToForward(Selected);
		pOut->PrintMessage("Figure is sent to the front");
		return true;
	}
	else
	{
		pOut->PrintMessage("NO SELECTED FIGURE.");
		return false;
	}
}