#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\SelectAction.h"
#include "Actions\SwitchToPlayAction.h"
#include "Actions\SaveAction.h"
#include "Actions\ClearAllAction.h"
#include "Actions\SwitchToDrawAction.h"
#include "Actions\Delete.h"
#include "Actions\Copy.h"
#include "Actions/PickHide.h"
#include "Actions\Cut.h"
#include "Actions/AddSQAction.h"
#include "Actions/AddHexAction.h"
#include "Actions/AddTriAction.h"
#include "Actions/AddCircleAction.h"
#include "Actions/Paste.h"
#include "Actions/ChangeFillingColorAction.h"
#include "Actions/ChangeBorderColorAction.h"
#include "Actions/Load.h"
#include "Actions/SendToBackAction.h"
#include "Actions/BringToForwardAction.h"
#include <iostream> 
using namespace std;
#include "CMUgraphicsLib/colors.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	
	FigCount = 0;
	SelectedFig = NULL;
	Clipboard = NULL;
		
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								VoiceOver						//
//==================================================================================//

void ApplicationManager::PlayActionSound(ActionType ActType) const
{
	if (ShouldPlayActionSound()) // If the user wants to play action sounds, play the corresponding sound
	{
		char* Filename = NULL; // Filename of the sound to be played

		switch (ActType) // Set the filename according to the action type
		{
		case DRAW_RECT:
			Filename = "sounds\\Rectangle.wav";
			break;
		case DRAW_SQ:
			Filename = "sounds\\Square.wav";
			break;
		case DRAW_TRI:
			Filename = "sounds\\Triangle.wav";
			break;
		case DRAW_CIRCLE:
			Filename = "sounds\\Circle.wav";
			break;
		case DRAW_HEX:
			Filename = "sounds\\Hexagon.wav";
			break;
		case FillColour:
			Filename = "sounds\\FillColorChanged.wav";
			break;
		case TO_DELETE:
			Filename = "sounds\\Deleted.wav";
			break;
		}

		if (Filename != NULL)
			PlaySound(Filename, NULL, SND_FILENAME | SND_ASYNC); // Play the sound
	}
}
bool ApplicationManager::ShouldPlayActionSound() const
{
	return PlayActionSoundEnabled;
}

void ApplicationManager::SetPlayActionSoundState(bool State)
{
	PlayActionSoundEnabled = State;		  // Set the flag to indicate whether the user wants to play action sounds or not
	pOut->SetPlayActionSoundState(State); // Set the flag in the output class as well (to change the color of the sound button)
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	//Ask the input to get the action from the user.
	return pIn->GetUserAction();		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	CFigure* random_fig = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;
		case DRAW_SQ:
			pAct = new AddSQAction(this);
			break;
		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;
		case DRAW_HEX:
			pAct = new AddHexAction(this);
			break;
		case DRAW_CIRCLE:
			pAct = new AddCircleAction(this);
			break;
		case SELECT:
			pAct = new SelectAction(this);
			break;
		case TO_PLAY:
			pAct = new SwitchToPlayAction(this);
			break;
		case SAVE:
			pAct = new SaveAction(this);
			break;
		case LOAD:
			pAct = new LoadAction(this);
			break;
		case CLEAR:
			pAct = new ClearAllAction(this);
			break;
		case filling:
			pAct = new ChangeFillingColorAction(this);
			break;
		case ChangeBorder:
			pAct = new ChangeBorderColorAction(this);
			break;
		case TO_DRAW:
			restoreGraph();
			pAct = new SwitchToDrawAction(this);
			break;
		case TO_DELETE:
			pAct = new Delete(this);
			break;
		case COPY:
			pAct = new Copy(this);
			break;
		case CUT:
			pAct = new Cut(this);
			break;
		case PASTE:
			pAct = new Paste(this);
			break;
		case pickbytype:
			restoreGraph();
			random_fig = RandomType();
			pAct = new PickHide(this, pickbytype, random_fig);
			break;
		case pickbycolor:
			restoreGraph();
			random_fig = RandomType();
			pAct = new PickHide(this, pickbycolor, random_fig);
			break;
		case pickbyboth:
			restoreGraph();
			random_fig = RandomType();
			pAct = new PickHide(this, pickbyboth, random_fig);
			break;
		case sendbackward:
			pAct = new SendToBackAction(this);
			break;
		case sendforward:
			pAct = new BringToForwardAction(this);
			break;
		case EXIT:
			break;
		
		case STATUS:	//a click on the status bar ==> no action
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//You may need to change this line depending to your implementation
		pAct = NULL;
	}
}

CFigure* ApplicationManager::RandomType()
{
	int random_number = rand() % FigCount;
	return FigList[random_number];
}
int ApplicationManager::GetFigCount() const
{
	return FigCount;
}
void ApplicationManager::setFigCount(int count)
{
	FigCount = count;
}
//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		FigList[FigCount++] = pFig;	
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL

	CFigure* fig = NULL;
	//Add your code here to search for a figure given a point x,y	
	//Remember that ApplicationManager only calls functions do NOT implement it.
	//DONE
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isInside(x, y))
			fig = FigList[i];
	}

	return fig;
}
CFigure* ApplicationManager::GetSelected()
{
	return SelectedFig; // Return the selected figure
}

void ApplicationManager::SetSelected(CFigure* c)
{
	SelectedFig = c; // Set the selected figure
}

/////////////////////////////////////////////////////////////////////////////////////////
//set clipboard:
void ApplicationManager::SetClipboard(CFigure* setclipboard)  // Set the clipboard (for the copy)
{
	Clipboard = setclipboard;
} 
/////////////////////////////////////////////////////////////////////////////////////////
//get clipoard:
CFigure * ApplicationManager::GetClipboard() 
{
	return Clipboard;


}

////////////////////////////////////////////////////////////////////////////

//==================================================================================//
//						Save & Load Functions										//
//==================================================================================//

void ApplicationManager::SaveAll(ofstream& FileOutputStream)
{
	FileOutputStream << UI.DrawColor << " " << UI.FillColor << endl;
	FileOutputStream << FigCount << endl;
	for (int i = 0; i < FigCount; i++)
		FigList[i]->Save(FileOutputStream);
}

//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	for(int i=0; i<FigCount; i++)
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
}



//DONE : Delete all figures
void ApplicationManager::ClearFigures()
{
	for (int i = 0; i < FigCount; i++)
	{
		delete FigList[i];
		FigList[i] = NULL;
	}
	FigCount = 0;
}
void ApplicationManager::ResetColors()
{
	UI.DrawColor = BLUE;
	UI.BkGrndColor = WHITE;
	UI.FillColor = TRANSPARENT_COLOR;
	UI.PenWidth = 3;
}

void ApplicationManager::DeleteFigure(int id)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (id == FigList[i]->getID())
		{
			delete FigList[i];
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
			break;
		}
	}
}

void ApplicationManager::DeleteFigureTemporary(int id)
{
	for (int i = 0; i < FigCount; i++)
	{
		if (id == FigList[i]->getID())
		{
			FigList[i] = FigList[FigCount - 1];
			FigList[FigCount - 1] = NULL;
			FigCount--;
			break;
		}
	}
}

void ApplicationManager::ClearDrawingArea() const
{
	pOut->ClearDrawArea();
}

int ApplicationManager::getCountFiguresByColor(color random_color)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->getColor() == random_color)
			count++;
	}
	return count;
}

int ApplicationManager::getCountFiguresByType(string Type)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->getTypeName() == Type)
			count++;
	}
	return count;
}

int ApplicationManager::getCountFiguresByTypeColor(string Type, color random_color)
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->getTypeName() == Type && FigList[i]->getColor() == random_color)
			count++;
	}
	return count;
}

void ApplicationManager::restoreGraph()
{
	for (int i = 0; i < countDeletedFigures; i++)
	{
		AddFigure(deletedFigures[i]);
	}
	UpdateInterface();
}

void ApplicationManager::AddDeletedFigures(CFigure** deletedFigs, int numDeletedFigures)
{
	countDeletedFigures = numDeletedFigures;
	deletedFigures = new CFigure* [countDeletedFigures];
	for (int i = 0; i < countDeletedFigures; i++)
	{
		deletedFigures[i] = deletedFigs[i];
	}
}

int ApplicationManager::getCountFilledFigures()
{
	int count = 0;
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->isFilled())
			count++;
	}
	return count;
}

void ApplicationManager::BringToForward(CFigure* SelectedFig)
{
	CFigure* TempFigure = SelectedFig;
	DeleteFigureTemporary(SelectedFig->getID());
	AddFigure(TempFigure);
}

void ApplicationManager::SendToBack(CFigure* SelectedFig)
{
	CFigure* TempFigure = SelectedFig;
	for (int i = FigCount - 1; i > 0; --i)
	{
		FigList[i] = FigList[i - 1];
	}
	FigList[0] = TempFigure;
}



////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }
//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }
////////////////////////////////////////////////////////////////////////////////////
//Destructor
ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	delete pIn;
	delete pOut;
	
}
