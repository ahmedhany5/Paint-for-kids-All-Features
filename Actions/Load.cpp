#include "Load.h"
#include "..\Figures\CCircle.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CSquare.h"
#include "..\Figures\CHexagon.h"
#include "..\Figures\CTriangle.h"
#include "ClearAllAction.h"
#include "fstream"
using namespace std;
LoadAction::LoadAction(ApplicationManager* pApp) : Action(pApp)
{
}

void LoadAction::ReadActionParameters()
{
	Input* pIn = pManager->GetInput();
	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Loading File: Enter File Name or Press esc to Cancel");
	FileName = pIn->GetString(pOut);
}

bool LoadAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	ReadActionParameters();
	ifstream FileInputStream;
	FileInputStream.open(FileName + ".txt", ios::app); // load graph from Saved Graphs \ FileName
	if (FileInputStream.is_open())
	{
		pOut->PrintMessage("Opened Load File Successfully");
		pManager->ClearFigures();
		pManager->ClearDrawingArea();
		pManager->SetSelected(NULL);
		pManager->SetClipboard(NULL);

		std::string x;
		CFigure* Figure;
		pOut->CreateDrawToolBar(); // To update border width icon
		UI.PenWidth = 3;
		UI.BkGrndColor = BASE;
		while (!FileInputStream.eof())
		{
			FileInputStream >> UI.DrawColor >> UI.FillColor;
			int count;
			FileInputStream >> count;
			pManager->setFigCount(count);
			//Point emptyP = Point();
			//GfxInfo emptyGFX = GfxInfo();
			//for (int i = 0; i < count; i++) // load all figures
			//{
			//	FileInputStream >> x;
			//	if (x == "RECTANGLE" || x == "RECT")
			//		Figure = new CRectangle(emptyP,emptyP, emptyGFX);
			//	else if (x == "SQUARE")
			//		Figure = new CSquare(emptyP, emptyGFX); 
			//	else if (x == "HEXAGON" || x == "HEX")
			//		Figure = new CHexagon(emptyP, emptyGFX);
			//	else if (x == "TRIANGLE" || x == "TRI")
			//		Figure = new CTriangle(emptyP, emptyP, emptyP, emptyGFX);
			//	//else if (x == "CIRCLE")
			//		//Figure = new CCircle();
			//	Figure->Load(FileInputStream);
			//	pManager->AddFigure(Figure);
			//}
			//FileInputStream >> x;
		}
		if (UI.BkGrndColor == TRANSPARENT_COLOR)UI.BkGrndColor = BASE;
		FileInputStream.close();
		return 1;
	}
	pOut->PrintMessage("Please Enter a Valid File Name");
	return 0;
}

