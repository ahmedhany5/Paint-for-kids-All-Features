#include "ClearAllAction.h"
#include "..\Figures\CFigure.h"



ClearAllAction::ClearAllAction(ApplicationManager* pApp): Action(pApp)
{
}

void ClearAllAction::ReadActionParameters()
{
}

bool ClearAllAction::Execute()
{
	
	Output* pOut = pManager->GetOutput();
	pManager->ClearFigures();
	pManager->ClearDrawingArea();
	pOut->PrintMessage("Figures Deleted");


	return false;
}
