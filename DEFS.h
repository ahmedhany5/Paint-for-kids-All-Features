#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_RECT,	//Draw Rectangle
	DRAW_SQ,
	DRAW_TRI,
	DRAW_HEX,
	DRAW_CIRCLE,
	SELECT,
	filling,
	ChangeBorder,
	TO_DELETE,
	CLEAR,
	COPY,
	CUT,
	PASTE,
	sendforward,
	sendbackward,
	SAVE,
	LOAD,
	pickbytype,
	pickbycolor,
	pickbyboth,
	EXIT,			//Exit
	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,		//Switch interface to Play mode
	EMPTY,			//A click on empty place in the toolbar
	DRAWING_AREA,	//A click on the drawing area
	FigureType,
	FillColour,
	TypeAndFillColour,
	STATUS,         //A click on the status bar
	//DONE

	///TODO: Add the other action types of the two modes
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif