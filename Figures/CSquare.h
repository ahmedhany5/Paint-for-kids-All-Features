#pragma once
#include<iostream>
using namespace std;
#ifndef CSQ_H
#define CSQ_H
#include "CFigure.h"
class CSquare : public CFigure // CSquare inherites from CFigure 
{
private:
	Point Corner1;	// 1 point for the sqaure and length
	int length;
public:
	CSquare(Point, GfxInfo FigureGfxInfo);	// 1 point, id, and its figure for the sqaure 
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(int x, int y);						//check if the coordinates (x,y) lies inside the figure
	virtual void Save(ofstream& OutFile);						//save figure parameters in the file
	void Load(ifstream& Infile); 					//load figure parameters in the file
	virtual void PrintInfo(Output* pOut);	                	//print all figure info on the status bar
};
#endif