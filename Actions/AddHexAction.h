#pragma once
#ifndef ADD_HEX_ACTION_H
#define ADD_HEX_ACTION_H
#include "Action.h"
#include <iostream>
using namespace std;

class AddHexAction: public Action // Hexagon action class inherites from action class
{
private:
	Point P1;	//Hexagon 1 Corner only
	GfxInfo HexGfxInfo;
public:
	AddHexAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();	// reads hexagon parameters to execute 
	virtual bool Execute();		// add hexagon to the ApplicationManager to execute the action 
};
#endif