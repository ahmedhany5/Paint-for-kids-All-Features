#pragma once
#ifndef ADD_SQ_ACTION_H
#define ADD_SQ_ACTION_H
#include "Action.h"
#include <iostream>

class AddSQAction: public Action	//Sqaure action class inherites from action class
{
private:
	Point P1;	//1 point only for the sqaure 
	GfxInfo SQGfxInfo;
public:
	AddSQAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();	//Reads sqaure parameters to execute
	virtual bool Execute();		//Add sqaure to the ApplicationManager to execute the action 
};
#endif