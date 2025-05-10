#pragma once
#ifndef CHANGE_BORDER-COLOR_ACTION_H
#define CHANGE_BORDER_COLOR_ACTION_H
#include "Action.h"
#include "..\ApplicationManager.h"
#include <iostream>
using namespace std;

class ChangeBorderColorAction : public Action
{
private:
	string ColorChosenS;
	color ColorChosen;
	CFigure* SelectedFig;

public:
	ChangeBorderColorAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute();
};
#endif