#pragma once
#include<iostream>
using namespace std;
#ifndef CHEX_H
#define CHEX_H
#include "CFigure.h"
class CHexagon : public CFigure // CHexagon inherites from CFigure 
{
private:
	Point Corner1;	// 1 point for the hexagon 

public:
	CHexagon(Point, GfxInfo FigureGfxInfo);		// takes 1 point, id, and its figure 
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(int x, int y);				//check if the coordinates (x,y) lies inside the figure
	virtual void Save(ofstream& OutFile);				//save figure parameters in the file
	virtual void Load(ifstream& Infile);		//load figure parameters in the file
	virtual void PrintInfo(Output* pOut);				//print all figure info on the status bar
};
#endif