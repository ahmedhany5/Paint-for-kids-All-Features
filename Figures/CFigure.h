#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphics info
	
	/// Add more parameters if needed.
	int RefCount;
	static int LastID;	  // Last ID given to a figure
	string TypeName; // Figure type name

public:
	CFigure();
	CFigure(GfxInfo FigureGfxInfo);
	static void ResetID();		// Resets the ID counter to 0
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	
	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	
	virtual void Load(ifstream &Infile) = 0;	//Load the figure parameters to the file

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar

	virtual bool isInside(int x, int y) = 0;   //check if the coordinates (x,y) lie inside the figure

	color getColor();
	bool isFilled() const;
	int getID() const;
	string getTypeName() const;
	string getColorName();
	color getBorderColor() const;
};
	
#endif