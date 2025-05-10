#pragma once
#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H
#include "Action.h"
#include <iostream>
using namespace std;

class AddCircleAction: public Action	// Circle action class inherites from action class
{
private:
	Point P1, P2; // 2 corners for the circle
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();	//Reads circle parameters to execute 
	virtual bool Execute();		//execute the action 
};
#endif