#pragma once
#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H
#include "Action.h"
#include <iostream>
using namespace std;

class AddTriAction: public Action	//Triangle action class inherites from action class
{
private:
	Point P1, P2, P3;		//Triangle takes 3 Corners
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();	//Reads Triangle parameters to execute 
	virtual bool Execute();		//Add Triangle to the ApplicationManager to execute the action 
};
#endif