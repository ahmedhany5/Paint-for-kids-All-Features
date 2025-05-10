#pragma once
#ifndef CHANGE_FILLING_COLOR_ACTION_H
#define CHANGE_FILLING_COLOR_ACTION_H
#include "Action.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

class ChangeFillingColorAction: public Action	//ChangeFillingColorAction class inherites from action class
{
	string ColorChosenS;
	color ColorChosen;
	CFigure* SelectedFig;
	
public:

	ChangeFillingColorAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();					//Reads the parameters to execute 
	virtual bool Execute();									//Add change filling color to the ApplicationManager to execute the action 
};
#endif