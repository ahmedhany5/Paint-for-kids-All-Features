#include "SaveAction.h"
using namespace std;
SaveAction::SaveAction(ApplicationManager* pApp): Action(pApp)
{
}

void SaveAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Saving File: Enter File Name or Press ESC to Cancel ");
	FileName = pIn->GetString(pOut);
}

bool SaveAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ofstream FileOutputStream;
	FileOutputStream.open(FileName + ".txt", ios::out);
	if(FileOutputStream.is_open())
	{
		pManager->SaveAll(FileOutputStream);
		pOut->PrintMessage("Created Save File Successfully");
		FileOutputStream.close();
		return true;
	}
	pOut->PrintMessage("Did not Create a File");
	return false;
}