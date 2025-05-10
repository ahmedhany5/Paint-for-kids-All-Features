#pragma once
#include<iostream>
using namespace std;
#ifndef CCIRCLE_H
#define CCIRCLE_H
#include "CFigure.h"
class CCircle : public CFigure // CCircle inherites  CFigure 
{
private:
	Point Corner1;	// 2 points for the circle 
	Point Corner2;
	double radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo);	// takes 2 points, id, and its figure
	virtual void Draw(Output* pOut) const;
	virtual bool isInside(int x, int y);				//check if the coordinates (x,y) lies inside the figure
	virtual void Save(ofstream& OutFile);				//save figure parametvoid Load(ifstream& Infile); // Load the figure parameters to the file
	virtual void PrintInfo(Output* pOut);	//print all figure info on the status bar
	double getCircleRadius();
	virtual void Load(ifstream& Infile);
};
#endif