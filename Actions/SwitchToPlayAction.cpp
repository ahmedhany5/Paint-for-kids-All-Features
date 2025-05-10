#include "SwitchToPlayAction.h"
#include "..\GUI\Output.h"
SwitchToPlayAction::SwitchToPlayAction(ApplicationManager* pApp): Action(pApp)
{
}
void SwitchToPlayAction::ReadActionParameters()
{
}

bool SwitchToPlayAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
	CFigure* SelectedFigure = pManager->GetSelected();
	if(SelectedFigure != NULL)
		SelectedFigure->SetSelected(false);					// Unselects the selected shape

	return true;
}