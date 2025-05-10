#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

	CFigure* Clipboard;  //Pointer to copied/cut figure

	CFigure** deletedFigures;
	int countDeletedFigures;


	bool PlayActionSoundEnabled;
public:	
	ApplicationManager(); 
	~ApplicationManager();


	void PlayActionSound(ActionType) const; // Plays a sound when an action is executed
	bool ShouldPlayActionSound() const;		// Returns whether the user wants to play action sounds or not
	void SetPlayActionSoundState(bool);		// Sets whether the user wants to play action sounds or not
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	CFigure* RandomType();
	int GetFigCount() const;
	void setFigCount(int count);

	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void SaveAll(ofstream&);			// Saves all figures in the FigList to the file
	void ClearFigures();				// Deletes all figures in the FigList
	void ResetColors();
	void DeleteFigure(int id);
	void DeleteFigureTemporary(int id);
	void ClearDrawingArea() const;
	int getCountFiguresByColor(color random_color);
	int getCountFiguresByType(string Type);
	int getCountFiguresByTypeColor(string Type, color random_color);
	void restoreGraph();
	void AddDeletedFigures(CFigure** deletedFigures, int countDeletedFigures);
	int getCountFilledFigures();
	

	CFigure* GetSelected();		 // Returns a pointer to the selected figure
	void SetSelected(CFigure*); // Sets the selected figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void SetClipboard(CFigure* setclipboard); //Set the Clipboard
	CFigure *GetClipboard();

	void BringToForward(CFigure* SelectedFig);
	void SendToBack(CFigure* SelectedFig);

};

#endif
//hello world