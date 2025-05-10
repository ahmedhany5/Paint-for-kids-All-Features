#pragma once
#include "Action.h"
#include "../Figures/CFigure.h"

class PickHide : public Action
{
private:
	Point selected_point;
	ActionType actType;
	CFigure* randomFigure;
	int correct;
	int wrong;
	CFigure** deletedFigures;
	int countDeletedFigures;


public:
	PickHide(ApplicationManager* pApp, ActionType type, CFigure* fig);  //Types: pickbytype, pickbycolor, pickbyboth 

	virtual void ReadActionParameters();

	virtual bool Execute();

};
