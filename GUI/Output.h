#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
	bool PlayActionSoundEnabled; // Indicates whether the program should play an action sound or not
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar() const;	//creates Draw mode toolbar & menu
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void ClearToolBar() const;

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	
	///DONE:Make similar functions for drawing all other figure types.
	void DrawSQ(Point P1, GfxInfo SQGfxInfo, bool selected = false) const; // Draw a Square
	void DrawTRI(Point P1, Point P2, Point P3, GfxInfo TriGfxInfo, bool selected = false) const; // Draw a Triangle //done
	void DrawHEX(Point P1, GfxInfo HexGfxInfo, bool selected = false) const; // Draw a Hexagonal
	void DrawCIRCLE(Point P1, Point P2, GfxInfo CircleGfxInfo, bool selected = false) const; // Draw a Circle

	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	color getBackgrndColor() const; //get background color
	int getCrntPenWidth() const;		//get current pen width

	void SetPlayActionSoundState(bool); // Changes play sound icon

	
	~Output();
};

#endif