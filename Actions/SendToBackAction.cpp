#include "SendToBackAction.h"
#include "../GUI/Output.h"
#include "../GUI/Input.h"
#include <iostream>
using namespace std;

SendToBackAction::SendToBackAction(ApplicationManager* pApp) : Action(pApp)
{}

void SendToBackAction::ReadActionParameters()
{}

bool SendToBackAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	CFigure* Selected = pManager->GetSelected();
	if (Selected != NULL)
	{
		pManager->SendToBack(pManager->GetSelected());
		pOut->PrintMessage("Figure sent to back.");
	}
	pManager->ClearDrawingArea();
	return true;
}