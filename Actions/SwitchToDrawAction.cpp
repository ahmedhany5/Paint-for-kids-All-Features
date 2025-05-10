#include "SwitchToDrawAction.h"
#include "..\GUI\Output.h"
#include "..\GUI\input.h"

#include "..\ApplicationManager.h"

SwitchToDrawAction::SwitchToDrawAction(ApplicationManager* pApp): Action(pApp)
{
}

void SwitchToDrawAction::ReadActionParameters()
{
}

bool SwitchToDrawAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->ClearToolBar();
	pOut->CreateDrawToolBar();
	CFigure* SelectedFigure = pManager->GetSelected();
	if (SelectedFigure != NULL)
		SelectedFigure->SetSelected(false);					// Unselects the selected shape

	return true;
}




